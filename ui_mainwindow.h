/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_Account;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_Password;
    QLabel *label_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *button_Account;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(485, 527);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"	\n"
"	\n"
"	background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 491, 291));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/ziyuan/2.png")));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(-130, -30, 481, 191));
        label_2->setStyleSheet(QString::fromUtf8(""));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(130, 300, 271, 45));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(34, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lineEdit_Account = new QLineEdit(widget_2);
        lineEdit_Account->setObjectName(QString::fromUtf8("lineEdit_Account"));
        lineEdit_Account->setStyleSheet(QString::fromUtf8("QLineEdit:hover{\n"
"border-style:ooutset;\n"
"border-radius:10px;\n"
"padding:6px;\n"
"background-color: rgb(255, 255, 127);\n"
"		 \n"
"}"));

        horizontalLayout->addWidget(lineEdit_Account);

        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(130, 360, 271, 45));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        horizontalSpacer_2 = new QSpacerItem(52, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lineEdit_Password = new QLineEdit(widget_3);
        lineEdit_Password->setObjectName(QString::fromUtf8("lineEdit_Password"));
        lineEdit_Password->setStyleSheet(QString::fromUtf8("QLineEdit:hover{\n"
"border-style:ooutset;\n"
"border-radius:10px;\n"
"padding:6px;\n"
"background-color: rgb(255, 255, 127);\n"
"		 \n"
"}"));
        lineEdit_Password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_Password);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 480, 121, 16));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(130, 420, 271, 50));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        button_Account = new QPushButton(widget);
        button_Account->setObjectName(QString::fromUtf8("button_Account"));
        button_Account->setStyleSheet(QString::fromUtf8("QPushButton:hover{color:rgb(255, 0, 0);\n"
"background-color: rgb(170, 255, 0);\n"
"}\n"
"QPushButton{background-color:rgb(170, 255, 255)}"));

        horizontalLayout_3->addWidget(button_Account);

        horizontalSpacer_3 = new QSpacerItem(86, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton:hover{color:rgb(255, 0, 0);\n"
"\n"
"	background-color: rgb(170, 255, 0);\n"
"}\n"
"QPushButton{\n"
"	background-color:rgb(170, 255, 255)\n"
"}\n"
""));

        horizontalLayout_3->addWidget(pushButton_5);

        MainWindow->setCentralWidget(centralWidget);
        label->raise();
        label_2->raise();
        widget_3->raise();
        widget_2->raise();
        label_3->raise();
        widget->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\231\272\350\203\275\347\240\201\345\244\264\351\233\206\350\243\205\347\256\261\347\256\241\346\216\247\345\271\263\345\217\260", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\224\257\346\214\201IPV6\347\275\221\347\273\234", nullptr));
        button_Account->setText(QCoreApplication::translate("MainWindow", "\346\263\250 \345\206\214", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\347\231\273 \345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
