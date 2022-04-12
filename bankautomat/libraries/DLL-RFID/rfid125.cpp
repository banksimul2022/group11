#include "rfid125.h"


RFID125::RFID125(QObject *parent) : QObject (parent)
{
    // allocate space in memory
    m_serialPort = new QSerialPort(this);
}

RFID125::~RFID125()
{
    disconnect(m_serialPort, SIGNAL(readyRead()), this, SLOT(receiveCardID()));
    delete m_serialPort;
}

void RFID125::readCardID()
{
    m_serialPort->setPortName("COM4");
    m_serialPort->open(QIODevice::ReadOnly);
    connect(m_serialPort, SIGNAL(readyRead()), this, SLOT(receiveCardID()));
    qDebug() << "Waiting for bankcard...";
}


void RFID125::receiveCardID()
{
    qDebug() << "Received data from Reader";
    QByteArray ID = m_serialPort->read(16).chopped(3).remove(0, 3);
    disconnect(m_serialPort, SIGNAL(readyRead()), this, SLOT(receiveCardID()));
    emit sendToExe(ID);
}
