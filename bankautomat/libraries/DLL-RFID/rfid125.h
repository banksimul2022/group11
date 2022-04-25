#ifndef RFID125_H
#define RFID125_H


#include "RFID125_global.h"
#include <QObject>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>

class RFID125_EXPORT RFID125 : public QObject
{
    Q_OBJECT
public:
    RFID125(QObject * parent = nullptr);
    ~RFID125();
    void readCardID();
    void testCardID();
signals:
    void sendToExe(QByteArray);
public slots:
    void receiveCardID();
private:
    QSerialPort *m_serialPort = nullptr;
    QByteArray ID;
};

#endif // RFID125_H
