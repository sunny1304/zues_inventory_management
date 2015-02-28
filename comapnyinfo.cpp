#include "comapnyinfo.h"
#include "ui_comapnyinfo.h"
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlRecord>
#include <QMessageBox>

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
    QString company_name    =  ui->company_name->text();
    QString company_address =  ui->company_address->text();
    QString company_phone   =  ui->company_phone->text();
    QString company_email   =  ui->company_email->text();
    QString compay_website  =  ui->company_website->text();

    QMessageBox message;

    if(company_name == "")
    {
        message.setWindowTitle("Error!!!");
        message.setText("You must enter your company name");
        message.exec();
    }
    else
    {
        QSqlQueryModel model;
        model.setQuery("select * from company");

        QSqlQuery query;
        QString add_edit_status;

        if( model.rowCount() < 1)
        {
            add_edit_status = "added";
            query.prepare("insert into company(name, address, email, phone, website) values(:name, :address, :email, :phone, :website)");
            query.bindValue(":name", company_name);
            query.bindValue(":address", company_address);
            query.bindValue(":phone", company_phone);
            query.bindValue(":email", company_email);
            query.bindValue(":website", compay_website);
        }
        else
        {
            add_edit_status = "updated";
            query.prepare("update company set name= :name, address= :address, phone= :phone, email= :email, website= :website where id=1");
            query.bindValue(":name", company_name);
            query.bindValue(":address", company_address);
            query.bindValue(":phone", company_phone);
            query.bindValue(":email", company_email);
            query.bindValue(":website", compay_website);
        }

        bool submit_check = query.exec();
        if (!submit_check)
        {
            qDebug() << query.lastError().text();

            this->close();
            message.setWindowTitle("Error!!!");
            message.setText("Company name must be unique");
            message.exec();
            return;
        }

        this->close();
        message.setWindowTitle("Success!");
        message.setText("Company information "+ add_edit_status + " successfully");
        message.exec();
    }
}



void ComapnyInfo::on_company_clear_button_clicked()
{
    ui->company_name->clear();
    ui->company_address->clear();
    ui->company_email->clear();
    ui->company_phone->clear();
    ui->company_website->setText("www.");
}

void ComapnyInfo::populate_edit_form()
{
    QSqlQueryModel model;
    model.setQuery("select * from company");

    QSqlRecord company = model.record(0);
    ui->company_name->setText(company.value("name").toString());
    ui->company_address->setText(company.value("address").toString());
    ui->company_phone->setText(company.value("phone").toString());
    ui->company_email->setText(company.value("email").toString());
    ui->company_website->setText(company.value("website").toString());

}
