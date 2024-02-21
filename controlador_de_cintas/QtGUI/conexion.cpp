#include "conexion.h"

conexion::conexion(QString nombre) : arduino(new QSerialPort), arduino_is_available(false), conexion_establecida(false), tiempoEsperaDesconexion(150000), contador(0)
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
        if (arduino->open(QSerialPort::ReadWrite)) {
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


void conexion::enviarEncenderT(std::string port) {
    qDebug() << "Encendiendo T...";
    if (arduino->isWritable()) {
        QByteArray comando = "encender T " + QByteArray::number(stoi(port)) + "\r\n";
        arduino->write(comando);
        arduino->waitForBytesWritten();
    } else {
        qDebug() << "No se puede escribir en el puerto serie.";
    }
}

void conexion::enviarEncenderI(std::string port) {
    if (arduino->isWritable()) {
        QByteArray comando = "encender I " + QByteArray::number(stoi(port)) + "\r\n";
        arduino->write(comando);
        arduino->waitForBytesWritten();
    } else {
        qDebug() << "No se puede escribir en el puerto serie.";
    }
}

void conexion::enviarApagarT(std::string port) {
    if (arduino->isWritable()) {
        QByteArray comando = "apagar T " + QByteArray::number(stoi(port)) + "\r\n";
        arduino->write(comando);
        arduino->waitForBytesWritten();
    } else {
        qDebug() << "No se puede escribir en el puerto serie.";
    }
}

void conexion::enviarApagarI(std::string port) {
    if (arduino->isWritable()) {
        QByteArray comando = "apagar I " + QByteArray::number(stoi(port)) + "\r\n";
        arduino->write(comando);
        arduino->waitForBytesWritten();
    } else {
        qDebug() << "No se puede escribir en el puerto serie.";
    }
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
            int sensor = numeros[0].toInt();
            if ((sensor == 2) || (sensor == 3) || (sensor == 4)){
                bool medicion = numeros[1].toInt(&ok);

            } else if ((sensor == 5) || (sensor == 6) || (sensor == 7)) {
                float medicion = numeros[1].toFloat(&ok);
            }
        }
    }
}


/*

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
            std::string sensor = numeros[0].toStdString();
            float medicion = numeros[1].toFloat(&ok);

            if (ok) {
                this->contador++;
                temporizadorTimeout->start();
                qDebug() << " - Contador: " << contador;

                // Crear una instancia del union Value
                Value port;

                // Intentar convertir el port a entero
                int portEntero = static_cast<int>(medicion);

                // Comprobar si el port es un entero (digital) o un flotante (analógico)
                if (medicion != static_cast<float>(portEntero)) {
                    // port analógico
                    port.analog = medicion;
                    qDebug() << "El sensor " << sensor << " del " << this->id << " envia el dato analógico: " << port.analog;
                } else {
                    // port digital
                    port.digital = portEntero;
                    qDebug() << "El sensor " << sensor << " del " << this->id << " envia el dato digital: " << port.digital;
                }

                // Cargar el port en la estructura Data
                Data aux;
                Port p;
                p.SetCode(sensor);

                aux.SetValue(port);
                aux.SetPort(p);

            }
        }
    }
}

*/
