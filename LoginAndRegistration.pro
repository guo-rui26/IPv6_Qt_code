#-------------------------------------------------
#
# Project created by QtCreator 2018-04-19T09:17:44
#
#-------------------------------------------------

QT       += core gui sql
QT       += network
QT       += charts


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LoginAndRegistration
TEMPLATE = app


SOURCES += main.cpp\
    chart.cpp \
    chartwindow.cpp \
    loginpass.cpp \
        mainwindow.cpp \
    dialog.cpp \
    fileoperator.cpp \
    user.cpp \
    mainwindow_menu.cpp \
    listwidget.cpp \
    database.cpp

HEADERS  += mainwindow.h \
    chart.h \
    chartwindow.h \
    dialog.h \
    fileoperator.h \
    loginpass.h \
    user.h \
    mainwindow_menu.h \
    listwidget.h \
    database.h

FORMS    += mainwindow.ui \
    chartwindow.ui \
    dialog.ui \
    mainwindow_menu.ui

RESOURCES += \
    ziyuan.qrc
