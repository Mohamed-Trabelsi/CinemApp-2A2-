#ifndef ARDUINO_H
#define ARDUINO_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
class Arduino
{
public:
    Arduino();
    int connectArduino();
    int closeArduino();
    int write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
    QByteArray* getserial();
    QString getarduino_port_name();
private:
    QSerialPort * serial;
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_avaiable;
    QByteArray data;
};

#endif // ARDUINO_H
