#ifndef ADDCONTROLLER_H
#define ADDCONTROLLER_H

#include <QDialog>

namespace Ui {
class addcontroller;
}

class addcontroller : public QDialog
{
    Q_OBJECT

public:
    explicit addcontroller(QWidget *parent = nullptr);
    ~addcontroller();

signals:
    AgregarControlador();

private slots:
    void on_nombre_nuevo_controlador_returnPressed();

public slots:
    void on_btn_agregar_controlador_clicked();

private:
    Ui::addcontroller *ui;
    int numero_de_controladores;
};

#endif // ADDCONTROLLER_H
