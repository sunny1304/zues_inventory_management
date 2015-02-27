#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "comapnyinfo.h"
#include "vendoradd.h"
#include "customeradd.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    cominfo->show();
}

void MainWindow::on_actionAdd_Vendor_triggered()
{
    qDebug() << "add vendor clicked";
    VendorAdd* add_vendor = new VendorAdd;
    add_vendor->show();
}

void MainWindow::on_actionAdd_Customer_triggered()
{
    qDebug() << "add Customer clicked";
    CustomerAdd* add_customer = new CustomerAdd;
    add_customer->show();

}
