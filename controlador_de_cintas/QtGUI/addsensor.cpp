#include "addsensor.h"
#include "ui_addsensor.h"

addsensor::addsensor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addsensor)
{
    ui->setupUi(this);
}

addsensor::~addsensor()
{
    delete ui;
}



void addsensor::on_btn_agregar_nuevo_T_clicked(){
    std::string pin = 0;
    int error = 0;
    std::string nombre;
    QString texto;


    if(ui->rb_T_pin_1->isChecked() == true){
        pin = "5";
    } else if (ui->rb_T_pin_2->isChecked() == true){
        pin = "6";
    } else if (ui->rb_T_pin_1->isChecked() == true) {
        pin = "7";
    } else {
        QMessageBox::critical(this, "FALTO SELECCIONAR UN PIN", "Por favor, ingrese el pin donde se encuentra el sensor");
        error = 1;
    }

    texto = ui->T_nombre->text();

    if(!texto.isEmpty()){
        nombre = texto.toStdString();
    } else {
        QMessageBox::critical(this, "FALTO UN NOMBRE", "Por favor, ingrese un nombre para el sensor");
        error = 1;
    }

    if (error == 0){
        qDebug() << "El nombre es " << nombre << " y el pin = " << pin;

        emit AgregarSensorT(pin, nombre);
    }
}

void addsensor::on_btn_listo_clicked()
{
    this->close();
}


void addsensor::on_btn_agregar_nuevo_IR_clicked()
{
    std::string pin;
    int error = 0;
    std::string nombre;
    QString texto;


    if(ui->rb_IR_pin_1->isChecked() == true){
        pin = "2";
    } else if (ui->rb_IR_pin_2->isChecked() == true){
        pin = "3";
    } else if (ui->rb_IR_pin_1->isChecked() == true) {
        pin = "4";
    } else {
        QMessageBox::critical(this, "FALTO SELECCIONAR UN PIN", "Por favor, ingrese el pin donde se encuentra el sensor");
        error = 1;
    }

    texto = ui->nombre_IR->text();

    if(!texto.isEmpty()){
        nombre = texto.toStdString();
    } else {
        QMessageBox::critical(this, "FALTO UN NOMBRE", "Por favor, ingrese un nombre para el sensor");
        error = 1;
    }

    if (error == 0){
        qDebug() << "El nombre es " << nombre << " y el pin = " << pin;

        emit AgregarSensorIR(pin, nombre);
    }
}


void addsensor::on_btn_s_ir_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->s_ir);
}


void addsensor::on_btn_s_temperatura_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->s_t);
}

