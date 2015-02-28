#ifndef VENDORDISPLAY_H
#define VENDORDISPLAY_H

#include <QWidget>

namespace Ui {
class VendorDisplay;
}

class VendorDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit VendorDisplay(QWidget *parent = 0);
    ~VendorDisplay();

private:
    Ui::VendorDisplay *ui;
};

#endif // VENDORDISPLAY_H
