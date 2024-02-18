#ifndef ADDSENSOR_H
#define ADDSENSOR_H

#include <QDialog>

namespace Ui {
class addsensor;
}

class addsensor : public QDialog
{
    Q_OBJECT

public:
    explicit addsensor(QWidget *parent = nullptr);
    ~addsensor();

private:
    Ui::addsensor *ui;
};

#endif // ADDSENSOR_H
