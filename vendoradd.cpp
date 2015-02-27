#include "vendoradd.h"
#include "ui_vendoradd.h"

VendorAdd::VendorAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VendorAdd)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Vendor");
}

VendorAdd::~VendorAdd()
{
    delete ui;
}
