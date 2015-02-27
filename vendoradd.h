#ifndef VENDORADD_H
#define VENDORADD_H

#include <QDialog>

namespace Ui {
class VendorAdd;
}

class VendorAdd : public QDialog
{
    Q_OBJECT

public:
    explicit VendorAdd(QWidget *parent = 0);
    ~VendorAdd();

private:
    Ui::VendorAdd *ui;
};

#endif // VENDORADD_H
