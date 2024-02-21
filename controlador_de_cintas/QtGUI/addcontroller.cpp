#include "addcontroller.h"
#include "ui_addcontroller.h"

addcontroller::addcontroller(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addcontroller)
{
    ui->setupUi(this);
}

addcontroller::~addcontroller()
{
    delete ui;
}

void addcontroller::on_nombre_nuevo_controlador_returnPressed(){

}


void addcontroller::on_btn_agregar_controlador_clicked(){

    std::string nombre = ui->nombre_nuevo_controlador->text().toStdString();
    std::string idv_s = ui->idvendor->text().toStdString();
    std::string idp_s = ui->idproduct->text().toStdString();
    int idv, idp;
    int error = 0;

    if(nombre.empty()){
        QMessageBox::critical(this, "FALTO INGRESAR UN NOMBRE", "Por favor, ingrese un nombre");
        error = 1;

    }

    if(idv_s.empty()){
        QMessageBox::critical(this, "FALTO INGRESAR EL IDVENDOR", "Por favor, ingrese el IDVendor de la placa que desea conectar");
        error = 1;

    } else {
        idv = std::stoi(idv_s);
    }

    if(idp_s.empty()){
        QMessageBox::critical(this, "FALTO INGRESAR EL IDPRODUCT", "Por favor, ingrese el IDProduct de la placa que desea conectar");
        error = 1;

    } else {
        idp = std::stoi(idp_s);
    }

    if(error == 0){
        emit AgregarControlador(nombre, idv, idp);

    }

    //Agregar a la pizzarra

    this->close(); // Cierras la segunda ventana
}
