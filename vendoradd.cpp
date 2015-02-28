#include "vendoradd.h"
#include "ui_vendoradd.h"
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDebug>

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

void VendorAdd::on_vendor_submit_button_clicked()
{
    QString vendor_name     =  ui->vendor_name->text();
    QString vendor_address  =  ui->vendor_address->text();
    QString vendor_zip      =  ui->vendor_zip->text();
    QString vendor_email    =  ui->vendor_email->text();
    QString vendor_phone    =  ui->vendor_phone->text();
    QString vendor_website  =  ui->vendor_website->text();

    QMessageBox message;

    if(vendor_name == "")
    {
        message.setWindowTitle("error !!!");
        message.setText("You must enter a vendor name");
        message.exec();
    }

    else
    {
        QSqlQuery query;
        query.prepare("insert into vendor(name, address, zip, email, phone, website) values(:name, :address, :zip, :email, :phone, :website)");
        query.bindValue(":name", vendor_name);
        query.bindValue(":address", vendor_address);
        query.bindValue(":zip", vendor_zip);
        query.bindValue(":email", vendor_email);
        query.bindValue(":phone", vendor_phone);
        query.bindValue(":website", vendor_website);


        bool check_submit = query.exec();
        if(!check_submit)
        {
            qDebug() << query.lastError().text();
            message.setWindowTitle("error !!!");
            message.setText("Vendor name must be unique");
            message.exec();
        }

        else
        {
            this->close();
            message.setWindowTitle("Success !!!");
            message.setText("Vendor data is saved");
            message.exec();
        }
    }

}

void VendorAdd::on_vendor_clear_button_clicked()
{
    ui->vendor_name->clear();
    ui->vendor_address->clear();
    ui->vendor_zip->clear();
    ui->vendor_email->clear();
    ui->vendor_phone->clear();
    ui->vendor_website->setText("www.");
}
