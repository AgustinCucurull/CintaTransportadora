#include "conexion.h"

conexion::conexion(QString nombre) : arduino(new QSerialPort), arduino_is_available(false), conexion_establecida(false), tiempoEsperaDesconexion(15000), contador(0)
{
    this->id = nombre;
    temporizadorTimeout = new QTimer(this);
    temporizadorTimeout->setInterval(tiempoEsperaDesconexion);
    connect(temporizadorTimeout, &QTimer::timeout, this, &conexion::timeoutConexion);
    this->contador = 0;

    this->arduino = new QSerialPort;
    this->arduino_is_available = false;
    this->arduino_port_name = "";

    //Mirar los puertos del sistema
    qDebug() << "Number of ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &QSerialPortInfo, QSerialPortInfo::availablePorts()){
        if(QSerialPortInfo.hasVendorIdentifier() && QSerialPortInfo.hasProductIdentifier()){
            qDebug() << "Vendor ID: " << QSerialPortInfo.vendorIdentifier();
            qDebug() << "Product ID: " << QSerialPortInfo.productIdentifier();
        }
    }
}

void conexion::BuscarYConectar(int idv, int idp){

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        if (serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()) {
            if (serialPortInfo.vendorIdentifier() == idv && serialPortInfo.productIdentifier() == idp) {
                arduino_port_name = serialPortInfo.portName();
                arduino_is_available = true;
                break;
            }
        }
    }

    if (arduino_is_available) {
        arduino->setPortName(arduino_port_name);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        if (arduino->open(QSerialPort::ReadOnly)) {
            conexion_establecida = true;
            temporizadorTimeout->start();
            connect(arduino, &QSerialPort::readyRead, this, &conexion::datosRecibidos);
            qDebug() << "Conexión exitosa";
        } else {
            qDebug() << "Error al conectar...";
        }
    } else {
        qDebug() << "Arduino no encontrado";
    }
}

void conexion::timeoutConexion()
{
    qDebug() << "Timeout: No se recibieron paquetes recientemente. Desconexión detectada.";
    conexion_establecida = false;
}

bool conexion::GetEstadoDeConexion(){
    return this->conexion_establecida;
}

void conexion::datosRecibidos()
{
    QByteArray datos = arduino->readAll();
    bufferDatos.append(datos);

    while (bufferDatos.contains("\r\n")) {
        int indiceFinPaquete = bufferDatos.indexOf("\r\n");
        QByteArray paquete = bufferDatos.left(indiceFinPaquete);
        bufferDatos.remove(0, indiceFinPaquete + 2);

        QList<QByteArray> numeros = paquete.split(',');
        if (numeros.size() >= 2) {
            bool ok;
            int sensor = numeros[0].toInt(&ok);
            int elemento = numeros[1].toInt(&ok);

            if (ok) {
                this->contador++;
                temporizadorTimeout->start();
                qDebug() << " - Contador: " << contador;
                qDebug() << "El sensor " << sensor << " del " << this->id << " envia el dato: " << elemento;
                // </> Ya recibi los datos ahora que hago?
                //Buffer cola circular, cuando este a la mitad enviar...
            }
        }
    }
}
