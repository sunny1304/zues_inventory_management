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
    void populate_edit_form();

private slots:
    void on_company_submit_button_clicked();

    void on_company_clear_button_clicked();

private:
    Ui::ComapnyInfo *ui;
};

#endif // COMAPNYINFO_H
