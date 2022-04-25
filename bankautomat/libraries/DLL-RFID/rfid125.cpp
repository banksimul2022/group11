#include "rfid125.h"


RFID125::RFID125(QObject *parent) : QObject (parent)
{
    // allocate space in memory
    m_serialPort = new QSerialPort(this);
}

RFID125::~RFID125()
{
    delete m_serialPort;
}

void RFID125::readCardID()
{
    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
        if (port.productIdentifier() == 22 && port.vendorIdentifier() == 5562) {
            m_serialPort->setPort(port);
        }
    }

    if (!m_serialPort->open(QIODevice::ReadOnly)) {
        throw 404;
    }

    connect(m_serialPort, SIGNAL(readyRead()), this, SLOT(receiveCardID()));
    qDebug() << "Waiting for a card...";
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
