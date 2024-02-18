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
