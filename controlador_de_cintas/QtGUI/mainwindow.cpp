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

    this->add_sensor = new addsensor;

    this->add_belt = new addbelt;

    connect(add_controller, &addcontroller::AgregarControlador, this, &MainWindow::ActivarSegundoControlador);

    connect(add_sensor, &addsensor::AgregarSensorT, this, &MainWindow::AgregarSensorT);

    connect(add_sensor, &addsensor::AgregarSensorIR, this, &MainWindow::AgregarSensorIR);

    connect(add_belt, &addbelt::AgregarCinta, this, &MainWindow::AgregarCinta);

    this->contador_de_cintas = 0;

    this->contador_de_T = 0;

    this->contador_de_IR = 0;

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


    ui->f_c_1_t_1->setVisible(false);

    ui->f_c_1_t_2->setVisible(false);


    ui->f_c_1_ir_1->setVisible(false);

    ui->f_c_1_ir_2->setVisible(false);


    ui->f_c_1_cinta_1->setVisible(false);

    ui->f_c_1_cinta_2->setVisible(false);

    ui->f_c_1_cinta_3->setVisible(false);

    ui->f_c_1_cinta_4->setVisible(false);

    ui->f_c_1_cinta_5->setVisible(false);
}

void MainWindow::InicioElClockPrincipal(){
    this->clock_principal = new QTimer(this);

    connect(this->clock_principal, SIGNAL(timeout()), this, SLOT(on_clock_principal_timeout()));

    this->clock_principal->start(500); // Inicia el temporizador con un intervalo de 1 segundo

}


void MainWindow::on_clock_principal_timeout(){

    if(this->conex1->GetEstadoDeConexion() == true){



    } else {

        qDebug() << "Volviendo a buscar...";
        BuscarArduino();

    }

}


void MainWindow::BuscarArduino(){
    int idv2 = 6790; // ID del fabricante de Arduino
    int idp2 = 29987;   // ID del producto de Arduino

    int idv1 =  9025;
    int idp1 =  67;

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
    this->add_belt->show();

}


void MainWindow::on_btn_addsensor_1_clicked()
{
    this->add_sensor->show();
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


void MainWindow::AgregarSensorT(std::string pin, std::string nombre){
    ui->f_c_1_t_1->setVisible(true);

    ui->lab_nombre_c_1_t_1->setText(QString::fromStdString(nombre));

    this->conex1->enviarEncenderT(pin);

    Port p;
    p.SetCode(pin);

    //AddSensorToSystem(nombre, p, lower_limit, upper_limit);


}

void MainWindow::AgregarSensorIR(std::string pin, std::string nombre){
    ui->f_c_1_ir_1->setVisible(true);

    ui->lab_nombre_c_1_ir_1->setText(QString::fromStdString(nombre));

    this->conex1->enviarEncenderI(pin);

    Port p;
    p.SetCode(pin);

    //AddSensorToSystem(nombre, Port port);

}

void MainWindow::AgregarCinta(std::string nombre, int largo){

    qDebug("Agragando cinta...");

    GestorDeVisualizacionDeCintas(nombre);
    /*

    this->conex1->enviarEncenderT(9);
    Port p;

    p.SetCode(pin);

    AddBeltToSystem(nombre, p, largo, velocidad);
*/
}

void MainWindow::GestorDeVisualizacionDeCintas(std::string nombre){
    switch (this->contador_de_cintas){
        case 0:
            ui->f_c_1_cinta_1->setVisible(true);
            ui->c_1_nombre_cinta_1->setText(QString::fromStdString(nombre));
            break;

        case 1:
            ui->f_c_1_cinta_2->setVisible(true);
            ui->c_1_nombre_cinta_2->setText(QString::fromStdString(nombre));
            break;

        case 2:
            ui->f_c_1_cinta_3->setVisible(true);
            ui->c_1_nombre_cinta_3->setText(QString::fromStdString(nombre));
            break;

        case 3:
            ui->f_c_1_cinta_4->setVisible(true);
            ui->c_1_nombre_cinta_4->setText(QString::fromStdString(nombre));
            break;

        case 4:
            ui->f_c_1_cinta_5->setVisible(true);
            ui->c_1_nombre_cinta_5->setText(QString::fromStdString(nombre));
            break;


        }

    this->contador_de_cintas++;

}
