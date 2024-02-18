#ifndef ADDBELT_H
#define ADDBELT_H

#include <QDialog>

namespace Ui {
class addbelt;
}

class addbelt : public QDialog
{
    Q_OBJECT

public:
    explicit addbelt(QWidget *parent = nullptr);
    ~addbelt();

private:
    Ui::addbelt *ui;
};

#endif // ADDBELT_H
