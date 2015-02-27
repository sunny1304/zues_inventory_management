#include "comapnyinfo.h"
#include "ui_comapnyinfo.h"
#include <QDebug>

ComapnyInfo::ComapnyInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComapnyInfo)
{
    ui->setupUi(this);
    this->setWhatsThis("Company Information");
    this->setWindowTitle("Comapny Information");
}

ComapnyInfo::~ComapnyInfo()
{
    delete ui;
}

void ComapnyInfo::on_company_submit_button_clicked()
{
    QString company_name = ui->company_name->text();
    if(company_name == "")
    {
        //ui->company_name_error->setText("You must enter your Company Name");
    }
    else
    {
        qDebug() << "company form clicked";
        this->close();
    }
}
