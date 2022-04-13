#include "rfid125.h"


RFID125::RFID125(QObject *parent) : QObject (parent)
{
    // allocate space in memory
    m_serialPort = new QSerialPort();
    m_serialPortInfo = new QSerialPortInfo();
}

RFID125::~RFID125()
{
    disconnect(m_serialPort, SIGNAL(readyRead()), this, SLOT(receiveCardID()));
    delete m_serialPort;
    delete m_serialPortInfo;
}

void RFID125::readCardID()
{
    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
        if (port.productIdentifier() == 22 && port.vendorIdentifier() == 5562) *m_serialPortInfo = port;
    }
    m_serialPort->setPort(*m_serialPortInfo);
    m_serialPort->open(QIODevice::ReadOnly);
    connect(m_serialPort, SIGNAL(readyRead()), this, SLOT(receiveCardID()));
    qDebug() << "Waiting for bankcard...";
}

void RFID125::testCardID()
{
    emit sendToExe(QByteArray("testOutput"));
}

void RFID125::receiveCardID()
{
    qDebug() << "Received data from Reader";
    QByteArray ID = m_serialPort->read(16).chopped(3).remove(0, 3);
    disconnect(m_serialPort, SIGNAL(readyRead()), this, SLOT(receiveCardID()));
    m_serialPort->close();
    emit sendToExe(ID);
}
