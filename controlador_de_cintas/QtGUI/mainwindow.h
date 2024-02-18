#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMessageBox>

#include "conexion.h"
#include "addbelt.h"
#include "addcontroller.h"
#include "addsensor.h"

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

private:
    Ui::MainWindow *ui;
    conexion * conex1;
    conexion * conex2;
    QTimer * clock_principal;
    addcontroller * add_controller;

};
#endif // MAINWINDOW_H
