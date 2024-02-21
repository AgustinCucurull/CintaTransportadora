#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMessageBox>
#include <string>

#include "conexion.h"
#include "addbelt.h"
#include "addcontroller.h"
#include "addsensor.h"
#include "data.h"
#include "port.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void ConfigurarVisibilidad();

    void InicioElClockPrincipal();

    void BuscarArduino();

private slots:
    void on_clock_principal_timeout();

    void on_btn_alarma_1_clicked();

    void on_btn_addcontroller_1_clicked();

    void on_btn_addbelt_1_clicked();

    void on_btn_addsensor_1_clicked();

    void ActivarSegundoControlador();

    void on_btn_c_1_clicked();

    void on_btn_c_2_clicked();

    void AgregarSensorT(std::string pin, std::string nombre);

    void AgregarSensorIR(std::string pin, std::string nombre);

    void AgregarCinta(std::string nombre, int largo);

    void GestorDeVisualizacionDeCintas(std::string nombre);
private:
    Ui::MainWindow *ui;
    conexion * conex1;
    conexion * conex2;
    QTimer * clock_principal;
    addcontroller * add_controller;
    addsensor * add_sensor;
    addbelt * add_belt;
    int contador_de_cintas;
    int contador_de_T;
    int contador_de_IR;

};
#endif // MAINWINDOW_H
