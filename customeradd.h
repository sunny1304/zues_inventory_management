#ifndef CUSTOMERADD_H
#define CUSTOMERADD_H

#include <QDialog>

namespace Ui {
class CustomerAdd;
}

class CustomerAdd : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerAdd(QWidget *parent = 0);
    ~CustomerAdd();

private:
    Ui::CustomerAdd *ui;
};

#endif // CUSTOMERADD_H
