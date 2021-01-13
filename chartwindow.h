#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QtGui>
#include "mainwindow_menu.h"
#include <QtCharts>
namespace Ui {
class ChartWindow;
}

class ChartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChartWindow(QWidget *parent = nullptr);
    ~ChartWindow();
    MainWindow_menu *mu;


private slots:
    void getData();
    void getData1();

    void on_btn_open_clicked();


    void on_btn_close_clicked();

private:
    Ui::ChartWindow *ui;
    bool open;  //开关
    qreal t = 0;
    int max_X =100;
    int Timer ;
    QTimer *timer2;
//    QTimer *timer1;
     QImage image;
protected:

void timerEvent(QTimerEvent *event);

};

#endif // CHARTWINDOW_H
