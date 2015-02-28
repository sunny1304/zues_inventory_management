#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets/QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    QRect rect = QApplication::desktop()->screenGeometry();
//    w.setFixedSize(rect.width()*0.8, rect.height()*0.8);
    w.show();

    return a.exec();
}
