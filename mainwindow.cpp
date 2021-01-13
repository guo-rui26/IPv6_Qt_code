#include <QMessageBox>
#include <QDialog>
#include <QLineEdit>
#include "fileoperator.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "mainwindow_menu.h"
#include "database.h"
#include <QSettings>
#include "loginpass.h"

#include <QtCore>
#include <QtNetwork>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QFile>
#include <QJsonObject>

#include <QJsonArray>
#include <QTimer>
const QString URLSTR5 = "http://[2001:da8:270:2021::f9]/login_pass.json";
const QString URLSTR6 = "http://[2001:da8:270:2021::f9]/user_login.json";

const QString FILE_NAME5 = "login_pass.json";
const QString FILE_NAME6 = "user_login.json";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height()); //禁止拖放窗口大小

    ui->lineEdit_Account->setAlignment(Qt::AlignHCenter);
    ui->lineEdit_Account->setPlaceholderText("用户名");
    ui->lineEdit_Password->setAlignment(Qt::AlignHCenter);
    ui->lineEdit_Password->setPlaceholderText("密码");

    QString user=ui->lineEdit_Account->text();
    QString pass=ui->lineEdit_Password->text();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//QString MainWindow::getNamepwd()
//{

//}

MainWindow *MainWindow::getmwInstence()
{
    static MainWindow m;
    return &m;
}

void MainWindow::Sendlogindata()//登录信息发送
{
    QString name=ui->lineEdit_Account->text();
    QString pwd=ui->lineEdit_Password->text();
    qDebug()<<name<<endl;
     qDebug()<<pwd<<endl;

    QNetworkRequest request2;
    QEventLoop loop;
    QNetworkAccessManager  m_httpManager;
    QNetworkReply * m_httpReply;
    QNetworkRequest  m_httpRequest;
    QByteArray  m_httpData;
    QJsonDocument m_httpDocum;
    QJsonObject _exampleObject;

    _exampleObject.insert("login_state", "1");
    _exampleObject.insert("username", name);
    _exampleObject.insert("password", pwd);
    //post请求的数据是Json格式。首先创建QJsonObject对象，并插入数据。
    m_httpDocum.setObject(_exampleObject);
    m_httpData = m_httpDocum.toJson(QJsonDocument::Compact);
    QUrl _url(URLSTR6);
    m_httpRequest.setUrl(_url);
    // 设置请求的url 注意地址的正确性 之前我就受到了http和https的坑
    m_httpRequest.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    // 设置请求头
    m_httpReply = m_httpManager.post(m_httpRequest, m_httpData);
    // post请求
    QEventLoop _loop;
    QTimer _timer;
    QObject::connect(m_httpReply, SIGNAL(finished()), &_loop, SLOT(quit()));
    QObject:: connect(&_timer, SIGNAL(timeout()), &_loop, SLOT(quit()));
    // eventloop用于阻塞等待消息，并结合timer进行超时处理
    _timer.start(1000);
    _loop.exec();
    qDebug()<<"发送完毕"<<endl;

}

bool MainWindow::loginflagstate()
{
    QUrl url(URLSTR5);
    QNetworkAccessManager manager1;
    QEventLoop loop1;
    QNetworkReply *reply1;

    qDebug() << "Reading html code form " << URLSTR5;
    reply1 = manager1.get(QNetworkRequest(url));
    //请求结束并下载完成后，退出子事件循环
    QObject::connect(reply1, SIGNAL(finished()), &loop1, SLOT(quit()));
    //开启子事件循环
    loop1.exec();

    //获取源码，打开文件
    QFile file(FILE_NAME5);
    if( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        qDebug() << "Cannot open the file: " << FILE_NAME5;
    }
    QTextStream out(&file);
    const QByteArray codeContent = reply1->readAll();


    QJsonParseError json_error;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(codeContent, &json_error));

    if(json_error.error != QJsonParseError::NoError)
    {
        qDebug() << "json1 error!";
    }

    QJsonObject rootObj = jsonDoc.object();

    QStringList keys = rootObj.keys();
    if(rootObj["login_pass"].toString() == "0")
    {
        //密码错误
         return false;

    }
    if(rootObj["login_pass"].toString() == "1")
    {
        //查无此用户
         return false;

    }
//    &&(ui->lineEdit_Account->text()==rootObj["name"].toString())&&(ui->lineEdit_Password->text()==rootObj["pwd"].toString())
    if((rootObj["login_pass"].toString() == "2"))
    {
        //登陆成功
        return true;

    }
    file.close();

}

void MainWindow::Delay_MSec(unsigned int msec)
{
    QEventLoop loop;//定义一个新的事件循环
    QTimer::singleShot(msec, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
    loop.exec();//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出
}



void MainWindow::on_pushButton_5_clicked()
{
    //1.获取用户名和密码
    QString name=ui->lineEdit_Account->text();
    QString pwd=ui->lineEdit_Password->text();
    if((!name.isEmpty())&&(!pwd.isEmpty()))
    {
      Sendlogindata();

       Delay_MSec(1000);
      bool ret1=loginflagstate();
       Delay_MSec(1000);
      if(ret1)
      {
          MainWindow_menu *mw = new MainWindow_menu();
          connect(this, SIGNAL(sendUsrname(QString)), mw, SLOT(recUsrname(QString)));


          mw->setAttribute(Qt::WA_DeleteOnClose);
          this->close();
          mw->show();

          qDebug()<<"打开窗口成功"<<endl;

      }

//      DataBase* pdb = DataBase::getDatabaseInstence();
//    bool ret1 = pdb->findUsr(name);
//    if(ret1)
//    {
//        bool ret2 = pdb->judge(name, pwd);
//        if (ret2)
//        {
//            //登录成功显示主窗口
//            MainWindow_menu *mw = new MainWindow_menu();

//            //建立连接
//            connect(this, SIGNAL(sendUsrname(QString)), mw, SLOT(recUsrname(QString)));

//            //发射信号
//            emit sendUsrname(name);

//            mw->setAttribute(Qt::WA_DeleteOnClose);
//            this->close();
//            mw->show();
////            this->hide();
//        }
//        else
//        {
//            QMessageBox::information(this, "提示", "登入失败！用户名或密码错误", QMessageBox::Ok);
//        }
//    }
//    }
//    else
//    {
//        QMessageBox::information(this, "提示", "登入失败！未注册，请先注册", QMessageBox::Ok);
    }

}

//void MainWindow::on_pushButton_2_clicked()
//{
//    Dialog dlg;
//    connect ( &dlg, SIGNAL (send(QString ,QString )),this, SLOT(receive(QString ,QString )) );
//    dlg.exec();
//}

void MainWindow::receive(QString suername, QString passward)
{
    ui->lineEdit_Account->setText(suername);
    ui->lineEdit_Password->setText(passward);
}


void MainWindow::on_button_Account_clicked()
{
    Dialog dlg;
    connect ( &dlg, SIGNAL (send(QString ,QString )),this, SLOT(receive(QString ,QString )) );
    dlg.exec();
}
