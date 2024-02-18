#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->conex1 = new conexion("Arduino 1");

    this->conex2 = new conexion("Arduino 2");

    this->add_controller = new addcontroller;

    connect(add_controller, &addcontroller::AgregarControlador, this, &MainWindow::ActivarSegundoControlador);

    ConfigurarVisibilidad();

    InicioElClockPrincipal();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ConfigurarVisibilidad(){
    ui->btn_desconectado->setVisible(true);

    ui->btn_conectado->setVisible(false);

    ui->btn_conectado_2->setVisible(false);

    ui->btn_c_2->setVisible(false);

    ui->btn_alarma_1->setVisible(false);

    ui->btn_alarma_2->setVisible(false);

    ui->btn_objeto_sensor_ir_1_c_1->setVisible(false);

    ui->btn_nf_sensor_ir_2_c_1->setVisible(false);

}

void MainWindow::InicioElClockPrincipal(){
    this->clock_principal = new QTimer(this);

    connect(this->clock_principal, SIGNAL(timeout()), this, SLOT(on_clock_principal_timeout()));

    this->clock_principal->start(1000); // Inicia el temporizador con un intervalo de 1 segundo

}


void MainWindow::on_clock_principal_timeout(){

    if(this->conex1->GetEstadoDeConexion() == true){

        // </> Recibir paquetes?

    } else {

        qDebug() << "Volviendo a buscar...";
        BuscarArduino();

    }

}


void MainWindow::BuscarArduino(){
    int idv1 = 6790; // ID del fabricante de Arduino
    int idp1 = 29987;   // ID del producto de Arduino

    int idv2 =  9025;
    int idp2 =  67;

    this->conex1->BuscarYConectar(idv1, idp1);
    this->conex2->BuscarYConectar(idv2, idp2);

    if(this->conex1->GetEstadoDeConexion() == true){

        ui->btn_desconectado->setVisible(false);

        ui->btn_conectado->setVisible(true);

        ui->btn_alarma_1->setVisible(true);

    } else {
        ui->btn_desconectado->setVisible(true);
    }

    if(this->conex2->GetEstadoDeConexion() == true){

        ui->btn_desconectado_2->setVisible(false);

        ui->btn_conectado_2->setVisible(true);

        ui->btn_alarma_2->setVisible(true);

    } else {
        ui->btn_desconectado_2->setVisible(true);
    }
}


void MainWindow::on_btn_alarma_1_clicked(){
    QMessageBox::StandardButton respuesta = QMessageBox::question(this, "ACTIVAR ALARMA", "¿Esta seguro de que desea activar la alarma?\n\n Con esta acción se pararan todas las cintas de este controlador", QMessageBox::Yes | QMessageBox::No);
        if (respuesta == QMessageBox::Yes) {
        qDebug() << "Alarma activada";
        // Aquí puedes colocar el código para activar la alarma
    } else {
        qDebug() << "Activación de alarma cancelada";
    }
}


void MainWindow::on_btn_addcontroller_1_clicked()
{
    this->add_controller->show();
}


void MainWindow::on_btn_addbelt_1_clicked()
{
    addbelt * add_belt_1 = new addbelt;
    add_belt_1->show();

}


void MainWindow::on_btn_addsensor_1_clicked()
{
    addsensor * add_sensor_1 = new addsensor;
    add_sensor_1->show();
}

void MainWindow::ActivarSegundoControlador(){
    ui->btn_c_2->setVisible(true);
}

void MainWindow::on_btn_c_1_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->controlador_1);
}


void MainWindow::on_btn_c_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->controlador_2);
}

