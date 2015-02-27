#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void on_actionZues_Inventory_Management_triggered();
    void on_actionCompany_Information_triggered();
    void on_actionEdit_Comapny_Information_triggered();
    void on_actionAdd_Vendor_triggered();
    void on_actionAdd_Customer_triggered();
};

#endif // MAINWINDOW_H
