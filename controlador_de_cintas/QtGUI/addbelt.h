#ifndef ADDBELT_H
#define ADDBELT_H

#include <QDialog>
#include <string>
#include <QMessageBox>

namespace Ui {
class addbelt;
}

class addbelt : public QDialog
{
    Q_OBJECT

public:
    explicit addbelt(QWidget *parent = nullptr);
    ~addbelt();

signals:
    AgregarCinta(std::string nombre, int largo);

private slots:
    void on_btn_agregar_cinta_clicked();

private:
    Ui::addbelt *ui;
};

#endif // ADDBELT_H
