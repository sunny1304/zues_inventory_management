#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "comapnyinfo.h"
#include "vendoradd.h"
#include "customeradd.h"
#include "vendordisplay.h"
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    /* In production Sqlite will be used. */

/*___________________ MySQL Connection _________________________*/

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("zues_inventory_management");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("1234");
    if (!db.open())
    {
        qDebug() << db.lastError().text();
    }
/*________________________________________________________________________*/

/* ___Necesary setup for menu buttons______ */

    ui->actionEdit_Comapny_Information->setDisabled(true);

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select id from company");
    if (model->rowCount() > 1)
    {
        ui->actionCompany_Information->setDisabled(true);
        ui->actionEdit_Comapny_Information->setEnabled(true);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionZues_Inventory_Management_triggered()
{
    qDebug() << "Home menu clicked";

}

void MainWindow::on_actionCompany_Information_triggered()
{
    ComapnyInfo *cominfo = new ComapnyInfo;
    cominfo->show();
}

void MainWindow::on_actionEdit_Comapny_Information_triggered()
{
    ComapnyInfo *cominfo = new ComapnyInfo;
    cominfo->populate_edit_form();
    cominfo->show();
}

void MainWindow::on_actionAdd_Vendor_triggered()
{
    qDebug() << "add Vendor clicked";
    VendorAdd* add_vendor = new VendorAdd;
    add_vendor->show();
}

void MainWindow::on_actionAdd_Customer_triggered()
{
    qDebug() << "add Customer clicked";
    CustomerAdd* add_customer = new CustomerAdd;
    add_customer->show();

}

void MainWindow::on_actionVendor_List_triggered()
{
    VendorDisplay* v_display = new VendorDisplay;
    ui->main_display_h_layout->addWidget(v_display);
    v_display->show();
}
