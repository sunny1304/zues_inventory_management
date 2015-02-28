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

private slots:
    void on_vendor_submit_button_clicked();

    void on_vendor_clear_button_clicked();

private:
    Ui::VendorAdd *ui;
};

#endif // VENDORADD_H
