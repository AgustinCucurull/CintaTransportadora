#include "addbelt.h"
#include "ui_addbelt.h"

addbelt::addbelt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addbelt)
{
    ui->setupUi(this);
}


addbelt::~addbelt()
{
    delete ui;
}


void addbelt::on_btn_agregar_cinta_clicked(){
    std::string nombre = ui->nombre_cinta->text().toStdString();
    int largo;
    int error = 0;

    if(ui->largo->text().isEmpty()){
        QMessageBox::critical(this, "FALTO INGRESAR EL LARGO", "Por favor, ingrese el largo de la cinta");
        error = 1;

    } else {
        largo = ui->largo->text().toInt();
    }

    if(nombre.empty()){
        QMessageBox::critical(this, "FALTO INGRESAR UN NOMBRE", "Por favor, ingrese un nombre");
        error = 1;

    }


    if(error == 0){
        emit AgregarCinta(nombre, largo);

        this->close();
    }
}
