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

void addcontroller::on_nombre_nuevo_controlador_returnPressed()
{

}


void addcontroller::on_btn_agregar_controlador_clicked()
{
    emit AgregarControlador();

    //Agregar a la pizzarra

    this->close(); // Cierras la segunda ventana
}
