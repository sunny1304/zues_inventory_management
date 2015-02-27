#include "customeradd.h"
#include "ui_customeradd.h"

CustomerAdd::CustomerAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerAdd)
{
    ui->setupUi(this);
}

CustomerAdd::~CustomerAdd()
{
    delete ui;
}
