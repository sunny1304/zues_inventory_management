#-------------------------------------------------
#
# Project created by QtCreator 2015-02-26T16:31:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = inventory_management
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    comapnyinfo.cpp \
    vendoradd.cpp \
    customeradd.cpp

HEADERS  += mainwindow.h \
    comapnyinfo.h \
    vendoradd.h \
    customeradd.h

FORMS    += mainwindow.ui \
    comapnyinfo.ui \
    vendoradd.ui \
    customeradd.ui
