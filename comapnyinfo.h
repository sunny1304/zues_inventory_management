#ifndef COMAPNYINFO_H
#define COMAPNYINFO_H

#include <QDialog>

namespace Ui {
class ComapnyInfo;
}

class ComapnyInfo : public QDialog
{
    Q_OBJECT

public:
    explicit ComapnyInfo(QWidget *parent = 0);
    ~ComapnyInfo();

private slots:
    void on_company_submit_button_clicked();

private:
    Ui::ComapnyInfo *ui;
};

#endif // COMAPNYINFO_H
