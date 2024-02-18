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
