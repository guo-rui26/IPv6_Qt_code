/********************************************************************************
** Form generated from reading UI file 'chartwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTWINDOW_H
#define UI_CHARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_ChartWindow
{
public:
    QWidget *centralwidget;
    QChartView *viewxy;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_open;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_close;
    QMenuBar *menubar;

    void setupUi(QMainWindow *ChartWindow)
    {
        if (ChartWindow->objectName().isEmpty())
            ChartWindow->setObjectName(QString::fromUtf8("ChartWindow"));
        ChartWindow->resize(671, 426);
        centralwidget = new QWidget(ChartWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        viewxy = new QChartView(centralwidget);
        viewxy->setObjectName(QString::fromUtf8("viewxy"));
        viewxy->setGeometry(QRect(20, 20, 631, 301));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(130, 340, 421, 50));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_open = new QPushButton(widget);
        btn_open->setObjectName(QString::fromUtf8("btn_open"));

        horizontalLayout->addWidget(btn_open);

        horizontalSpacer = new QSpacerItem(196, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_close = new QPushButton(widget);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        horizontalLayout->addWidget(btn_close);

        ChartWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChartWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 671, 26));
        ChartWindow->setMenuBar(menubar);

        retranslateUi(ChartWindow);

        QMetaObject::connectSlotsByName(ChartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChartWindow)
    {
        ChartWindow->setWindowTitle(QCoreApplication::translate("ChartWindow", "\350\275\246\350\276\206\344\275\215\347\275\256\350\267\237\350\270\252", nullptr));
        btn_open->setText(QCoreApplication::translate("ChartWindow", "\345\274\200\345\247\213", nullptr));
        btn_close->setText(QCoreApplication::translate("ChartWindow", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChartWindow: public Ui_ChartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTWINDOW_H
