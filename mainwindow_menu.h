#ifndef MAINWINDOW_MENU_H
#define MAINWINDOW_MENU_H
#include <QtCharts/QChart>
#include <QtCore/QTimer>
#include <QMainWindow>
class ListWidget;
extern int flag1;
namespace Ui {
class MainWindow_menu;
}

class MainWindow_menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_menu(QWidget *parent = 0);
    ~MainWindow_menu();
    void initData();
    int lastReadRowNums=0;//上次读到的文件行数，初始为0

      int flag = 0 ;




//      uint car_change;
signals:

private slots:
    //登录成功后接收用户名
    void recUsrname(QString name);
    void display();


    void on_ButtonSure_clicked();

    void on_ButtonCancel_clicked();
    void qtimeSlot();
//    void showFileContents();

    void figure();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_ButtonTerminal_clicked();
    void init();
    void SendTerminal();
    void SendStart();

    void on_ButtonStart_clicked();



    void on_ButtonYes_clicked();


    void on_ButtonDisplay_clicked();

    void on_timer_timeout();

private:
    Ui::MainWindow_menu *ui;
    ListWidget* listwidget_;
    QTimer *timer;
};

#endif // MAINWINDOW_MENU_H
