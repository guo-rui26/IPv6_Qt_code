/********************************************************************************
** Form generated from reading UI file 'mainwindow_menu.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_MENU_H
#define UI_MAINWINDOW_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_menu
{
public:
    QAction *actioncdc;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *ButtonSure;
    QPushButton *ButtonTerminal;
    QPushButton *ButtonStart;
    QPushButton *ButtonDisplay;
    QPushButton *ButtonCancel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *ButtonYes;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow_menu)
    {
        if (MainWindow_menu->objectName().isEmpty())
            MainWindow_menu->setObjectName(QString::fromUtf8("MainWindow_menu"));
        MainWindow_menu->setWindowModality(Qt::NonModal);
        MainWindow_menu->resize(537, 602);
        QPalette palette;
        QConicalGradient gradient(0.5, 0.5, 0);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(35, 40, 3, 255));
        gradient.setColorAt(0.16, QColor(136, 106, 22, 255));
        gradient.setColorAt(0.225, QColor(166, 140, 41, 255));
        gradient.setColorAt(0.285, QColor(204, 181, 74, 255));
        gradient.setColorAt(0.345, QColor(235, 219, 102, 255));
        gradient.setColorAt(0.415, QColor(245, 236, 112, 255));
        gradient.setColorAt(0.52, QColor(209, 190, 76, 255));
        gradient.setColorAt(0.57, QColor(187, 156, 51, 255));
        gradient.setColorAt(0.635, QColor(168, 142, 42, 255));
        gradient.setColorAt(0.695, QColor(202, 174, 68, 255));
        gradient.setColorAt(0.75, QColor(218, 202, 86, 255));
        gradient.setColorAt(0.815, QColor(208, 187, 73, 255));
        gradient.setColorAt(0.88, QColor(187, 156, 51, 255));
        gradient.setColorAt(0.935, QColor(137, 108, 26, 255));
        gradient.setColorAt(1, QColor(35, 40, 3, 255));
        QBrush brush(gradient);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(192, 200, 181, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        QConicalGradient gradient1(0.5, 0.5, 0);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(35, 40, 3, 255));
        gradient1.setColorAt(0.16, QColor(136, 106, 22, 255));
        gradient1.setColorAt(0.225, QColor(166, 140, 41, 255));
        gradient1.setColorAt(0.285, QColor(204, 181, 74, 255));
        gradient1.setColorAt(0.345, QColor(235, 219, 102, 255));
        gradient1.setColorAt(0.415, QColor(245, 236, 112, 255));
        gradient1.setColorAt(0.52, QColor(209, 190, 76, 255));
        gradient1.setColorAt(0.57, QColor(187, 156, 51, 255));
        gradient1.setColorAt(0.635, QColor(168, 142, 42, 255));
        gradient1.setColorAt(0.695, QColor(202, 174, 68, 255));
        gradient1.setColorAt(0.75, QColor(218, 202, 86, 255));
        gradient1.setColorAt(0.815, QColor(208, 187, 73, 255));
        gradient1.setColorAt(0.88, QColor(187, 156, 51, 255));
        gradient1.setColorAt(0.935, QColor(137, 108, 26, 255));
        gradient1.setColorAt(1, QColor(35, 40, 3, 255));
        QBrush brush2(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QConicalGradient gradient2(0.5, 0.5, 0);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(35, 40, 3, 255));
        gradient2.setColorAt(0.16, QColor(136, 106, 22, 255));
        gradient2.setColorAt(0.225, QColor(166, 140, 41, 255));
        gradient2.setColorAt(0.285, QColor(204, 181, 74, 255));
        gradient2.setColorAt(0.345, QColor(235, 219, 102, 255));
        gradient2.setColorAt(0.415, QColor(245, 236, 112, 255));
        gradient2.setColorAt(0.52, QColor(209, 190, 76, 255));
        gradient2.setColorAt(0.57, QColor(187, 156, 51, 255));
        gradient2.setColorAt(0.635, QColor(168, 142, 42, 255));
        gradient2.setColorAt(0.695, QColor(202, 174, 68, 255));
        gradient2.setColorAt(0.75, QColor(218, 202, 86, 255));
        gradient2.setColorAt(0.815, QColor(208, 187, 73, 255));
        gradient2.setColorAt(0.88, QColor(187, 156, 51, 255));
        gradient2.setColorAt(0.935, QColor(137, 108, 26, 255));
        gradient2.setColorAt(1, QColor(35, 40, 3, 255));
        QBrush brush3(gradient2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush3);
        QConicalGradient gradient3(0.5, 0.5, 0);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(35, 40, 3, 255));
        gradient3.setColorAt(0.16, QColor(136, 106, 22, 255));
        gradient3.setColorAt(0.225, QColor(166, 140, 41, 255));
        gradient3.setColorAt(0.285, QColor(204, 181, 74, 255));
        gradient3.setColorAt(0.345, QColor(235, 219, 102, 255));
        gradient3.setColorAt(0.415, QColor(245, 236, 112, 255));
        gradient3.setColorAt(0.52, QColor(209, 190, 76, 255));
        gradient3.setColorAt(0.57, QColor(187, 156, 51, 255));
        gradient3.setColorAt(0.635, QColor(168, 142, 42, 255));
        gradient3.setColorAt(0.695, QColor(202, 174, 68, 255));
        gradient3.setColorAt(0.75, QColor(218, 202, 86, 255));
        gradient3.setColorAt(0.815, QColor(208, 187, 73, 255));
        gradient3.setColorAt(0.88, QColor(187, 156, 51, 255));
        gradient3.setColorAt(0.935, QColor(137, 108, 26, 255));
        gradient3.setColorAt(1, QColor(35, 40, 3, 255));
        QBrush brush4(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        QConicalGradient gradient4(0.5, 0.5, 0);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(35, 40, 3, 255));
        gradient4.setColorAt(0.16, QColor(136, 106, 22, 255));
        gradient4.setColorAt(0.225, QColor(166, 140, 41, 255));
        gradient4.setColorAt(0.285, QColor(204, 181, 74, 255));
        gradient4.setColorAt(0.345, QColor(235, 219, 102, 255));
        gradient4.setColorAt(0.415, QColor(245, 236, 112, 255));
        gradient4.setColorAt(0.52, QColor(209, 190, 76, 255));
        gradient4.setColorAt(0.57, QColor(187, 156, 51, 255));
        gradient4.setColorAt(0.635, QColor(168, 142, 42, 255));
        gradient4.setColorAt(0.695, QColor(202, 174, 68, 255));
        gradient4.setColorAt(0.75, QColor(218, 202, 86, 255));
        gradient4.setColorAt(0.815, QColor(208, 187, 73, 255));
        gradient4.setColorAt(0.88, QColor(187, 156, 51, 255));
        gradient4.setColorAt(0.935, QColor(137, 108, 26, 255));
        gradient4.setColorAt(1, QColor(35, 40, 3, 255));
        QBrush brush5(gradient4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        QConicalGradient gradient5(0.5, 0.5, 0);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(35, 40, 3, 255));
        gradient5.setColorAt(0.16, QColor(136, 106, 22, 255));
        gradient5.setColorAt(0.225, QColor(166, 140, 41, 255));
        gradient5.setColorAt(0.285, QColor(204, 181, 74, 255));
        gradient5.setColorAt(0.345, QColor(235, 219, 102, 255));
        gradient5.setColorAt(0.415, QColor(245, 236, 112, 255));
        gradient5.setColorAt(0.52, QColor(209, 190, 76, 255));
        gradient5.setColorAt(0.57, QColor(187, 156, 51, 255));
        gradient5.setColorAt(0.635, QColor(168, 142, 42, 255));
        gradient5.setColorAt(0.695, QColor(202, 174, 68, 255));
        gradient5.setColorAt(0.75, QColor(218, 202, 86, 255));
        gradient5.setColorAt(0.815, QColor(208, 187, 73, 255));
        gradient5.setColorAt(0.88, QColor(187, 156, 51, 255));
        gradient5.setColorAt(0.935, QColor(137, 108, 26, 255));
        gradient5.setColorAt(1, QColor(35, 40, 3, 255));
        QBrush brush6(gradient5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        QConicalGradient gradient6(0.5, 0.5, 0);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(35, 40, 3, 255));
        gradient6.setColorAt(0.16, QColor(136, 106, 22, 255));
        gradient6.setColorAt(0.225, QColor(166, 140, 41, 255));
        gradient6.setColorAt(0.285, QColor(204, 181, 74, 255));
        gradient6.setColorAt(0.345, QColor(235, 219, 102, 255));
        gradient6.setColorAt(0.415, QColor(245, 236, 112, 255));
        gradient6.setColorAt(0.52, QColor(209, 190, 76, 255));
        gradient6.setColorAt(0.57, QColor(187, 156, 51, 255));
        gradient6.setColorAt(0.635, QColor(168, 142, 42, 255));
        gradient6.setColorAt(0.695, QColor(202, 174, 68, 255));
        gradient6.setColorAt(0.75, QColor(218, 202, 86, 255));
        gradient6.setColorAt(0.815, QColor(208, 187, 73, 255));
        gradient6.setColorAt(0.88, QColor(187, 156, 51, 255));
        gradient6.setColorAt(0.935, QColor(137, 108, 26, 255));
        gradient6.setColorAt(1, QColor(35, 40, 3, 255));
        QBrush brush7(gradient6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        QConicalGradient gradient7(0.5, 0.5, 0);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(35, 40, 3, 255));
        gradient7.setColorAt(0.16, QColor(136, 106, 22, 255));
        gradient7.setColorAt(0.225, QColor(166, 140, 41, 255));
        gradient7.setColorAt(0.285, QColor(204, 181, 74, 255));
        gradient7.setColorAt(0.345, QColor(235, 219, 102, 255));
        gradient7.setColorAt(0.415, QColor(245, 236, 112, 255));
        gradient7.setColorAt(0.52, QColor(209, 190, 76, 255));
        gradient7.setColorAt(0.57, QColor(187, 156, 51, 255));
        gradient7.setColorAt(0.635, QColor(168, 142, 42, 255));
        gradient7.setColorAt(0.695, QColor(202, 174, 68, 255));
        gradient7.setColorAt(0.75, QColor(218, 202, 86, 255));
        gradient7.setColorAt(0.815, QColor(208, 187, 73, 255));
        gradient7.setColorAt(0.88, QColor(187, 156, 51, 255));
        gradient7.setColorAt(0.935, QColor(137, 108, 26, 255));
        gradient7.setColorAt(1, QColor(35, 40, 3, 255));
        QBrush brush8(gradient7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        QConicalGradient gradient8(0.5, 0.5, 0);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(35, 40, 3, 255));
        gradient8.setColorAt(0.16, QColor(136, 106, 22, 255));
        gradient8.setColorAt(0.225, QColor(166, 140, 41, 255));
        gradient8.setColorAt(0.285, QColor(204, 181, 74, 255));
        gradient8.setColorAt(0.345, QColor(235, 219, 102, 255));
        gradient8.setColorAt(0.415, QColor(245, 236, 112, 255));
        gradient8.setColorAt(0.52, QColor(209, 190, 76, 255));
        gradient8.setColorAt(0.57, QColor(187, 156, 51, 255));
        gradient8.setColorAt(0.635, QColor(168, 142, 42, 255));
        gradient8.setColorAt(0.695, QColor(202, 174, 68, 255));
        gradient8.setColorAt(0.75, QColor(218, 202, 86, 255));
        gradient8.setColorAt(0.815, QColor(208, 187, 73, 255));
        gradient8.setColorAt(0.88, QColor(187, 156, 51, 255));
        gradient8.setColorAt(0.935, QColor(137, 108, 26, 255));
        gradient8.setColorAt(1, QColor(35, 40, 3, 255));
        QBrush brush9(gradient8);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        MainWindow_menu->setPalette(palette);
        MainWindow_menu->setAutoFillBackground(false);
        MainWindow_menu->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"	background-color: rgb(255, 255, 255);\n"
"	background-color: rgb(255, 255, 127);\n"
"	background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n"
"}"));
        actioncdc = new QAction(MainWindow_menu);
        actioncdc->setObjectName(QString::fromUtf8("actioncdc"));
        centralwidget = new QWidget(MainWindow_menu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 2, 0, 1, 1);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ButtonSure = new QPushButton(widget_3);
        ButtonSure->setObjectName(QString::fromUtf8("ButtonSure"));

        horizontalLayout->addWidget(ButtonSure);

        ButtonTerminal = new QPushButton(widget_3);
        ButtonTerminal->setObjectName(QString::fromUtf8("ButtonTerminal"));

        horizontalLayout->addWidget(ButtonTerminal);

        ButtonStart = new QPushButton(widget_3);
        ButtonStart->setObjectName(QString::fromUtf8("ButtonStart"));

        horizontalLayout->addWidget(ButtonStart);

        ButtonDisplay = new QPushButton(widget_3);
        ButtonDisplay->setObjectName(QString::fromUtf8("ButtonDisplay"));

        horizontalLayout->addWidget(ButtonDisplay);

        ButtonCancel = new QPushButton(widget_3);
        ButtonCancel->setObjectName(QString::fromUtf8("ButtonCancel"));

        horizontalLayout->addWidget(ButtonCancel);


        gridLayout->addWidget(widget_3, 3, 0, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(217, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        ButtonYes = new QPushButton(widget);
        ButtonYes->setObjectName(QString::fromUtf8("ButtonYes"));

        horizontalLayout_2->addWidget(ButtonYes);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        MainWindow_menu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow_menu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 537, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow_menu->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow_menu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setSizeGripEnabled(true);
        MainWindow_menu->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(MainWindow_menu);

        QMetaObject::connectSlotsByName(MainWindow_menu);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_menu)
    {
        MainWindow_menu->setWindowTitle(QCoreApplication::translate("MainWindow_menu", "\347\233\221\346\216\247\344\270\273\347\225\214\351\235\242", nullptr));
        actioncdc->setText(QCoreApplication::translate("MainWindow_menu", "\345\244\215\345\210\266", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow_menu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun';\"><br /></p></body></html>", nullptr));
        ButtonSure->setText(QCoreApplication::translate("MainWindow_menu", "\346\211\213\345\212\250\345\210\267\346\226\260", nullptr));
        ButtonTerminal->setText(QCoreApplication::translate("MainWindow_menu", "\350\275\246\350\276\206\345\201\234\346\255\242", nullptr));
        ButtonStart->setText(QCoreApplication::translate("MainWindow_menu", "\350\275\246\350\276\206\345\220\257\345\212\250", nullptr));
        ButtonDisplay->setText(QCoreApplication::translate("MainWindow_menu", "\345\235\220\346\240\207\346\230\276\347\244\272", nullptr));
        ButtonCancel->setText(QCoreApplication::translate("MainWindow_menu", "\351\200\200\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("MainWindow_menu", "\350\275\246\350\276\206\351\200\211\346\213\251", nullptr));
        ButtonYes->setText(QCoreApplication::translate("MainWindow_menu", "\346\225\260\346\215\256\346\230\276\347\244\272\345\220\257\345\212\250", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow_menu", "\346\254\242\350\277\216\350\277\233\345\205\245\346\231\272\350\203\275\347\240\201\345\244\264\350\275\246\350\276\206\347\256\241\346\216\247\345\271\263\345\217\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_menu: public Ui_MainWindow_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_MENU_H
