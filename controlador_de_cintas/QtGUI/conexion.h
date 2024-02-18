#ifndef CONEXION_H
#define CONEXION_H

#include <QObject>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QString>

class conexion : public QSerialPort
{

public:
    conexion(QString nombre);
    void BuscarYConectar(int idv, int idp);
    bool GetEstadoDeConexion();

private slots:
    void timeoutConexion();
    void datosRecibidos();

private:
    QString id;
    QSerialPort *arduino;
    QString arduino_port_name;
    bool arduino_is_available;
    bool conexion_establecida;
    QByteArray bufferDatos;
    QTimer *temporizadorTimeout;
    int tiempoEsperaDesconexion;
    int contador;
    // </> Aca se podria directamente tener una ventana de configuracion en la que se puedan añadir nuevas placas y usar un QFile o un QSettings para guardar los datos
};

#endif // CONEXION_H
