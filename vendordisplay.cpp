#include "vendordisplay.h"
#include "ui_vendordisplay.h"
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include <QPushButton>
#include <QDebug>

VendorDisplay::VendorDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VendorDisplay)
{
    ui->setupUi(this);

    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("vendor");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->removeColumn(0);
    model->insertColumn(model->columnCount());
    model->setHeaderData(model->columnCount()-1, Qt::Horizontal, QObject::tr("edit/remove"));
    qDebug() << model->columnCount();

    ui->vendor_table_view->setModel(model);
//    ui->vendor_table_view->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

VendorDisplay::~VendorDisplay()
{
    delete ui;
}
