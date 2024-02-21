#ifndef ADDSENSOR_H
#define ADDSENSOR_H

#include <QDialog>
#include <QMessageBox>
#include <string>

namespace Ui {
class addsensor;
}

class addsensor : public QDialog
{
    Q_OBJECT

public:
    explicit addsensor(QWidget *parent = nullptr);
    ~addsensor();


signals:
    AgregarSensorT(std::string pin, std::string nombre);
    AgregarSensorIR(std::string pin, std::string nombre);


private slots:
    void on_btn_agregar_nuevo_T_clicked();

    void on_btn_listo_clicked();

    void on_btn_agregar_nuevo_IR_clicked();

    void on_btn_s_ir_clicked();

    void on_btn_s_temperatura_clicked();

private:
    Ui::addsensor *ui;
};

#endif // ADDSENSOR_H
