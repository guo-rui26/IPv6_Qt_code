#include <QMessageBox>
#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "fileoperator.h"
#include "user.h"
#include "database.h"
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
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->comboBox->addItem("总经理");
    ui->comboBox->addItem("项目经理");
    ui->comboBox->addItem("一般管理人员");
    ui->comboBox->addItem("员工");
//    ui->comboBox->addItem("软件测试工程师");
//    ui->comboBox->addItem("UI设计师");
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::getnamepwd()
{
    return rname,rpassward;
}

void Dialog::setnamepwd(QString &value1, QString &value2)
{
    rname=value1;
    rpassward=value2;
}

void Dialog::Delay_MSec(unsigned int msec)
{
    QEventLoop loop;//定义一个新的事件循环
    QTimer::singleShot(msec, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
    loop.exec();//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出
}

void Dialog::on_pushButton_clicked()
{
    //注册时保存用户注册信息

    QString name=ui->edit_Name->text();
    QString pwd=ui->edit_Password->text();
    QString sex=ui->radioButton->isChecked() ? "Man" : "Woman";
    QString birthday=ui->edit_Date->text();
    QString major=ui->comboBox->currentText();
    //******************************************************************

    if((!name.isEmpty())&&(!pwd.isEmpty()))
    {
       User user(name, pwd, sex, birthday, major);

//    loginPass *lp=loginPass::getLoginPassInstence();

//    DataBase* pdb = DataBase::getDatabaseInstence();
//    bool ret = pdb->insertUsr(user);
        Sendregisterdata();

        Delay_MSec(2000);
        bool ret=registerflagstate();
        Delay_MSec(1000);
        if (ret)
        {
            Delay_MSec(2000);
            QMessageBox::information(this,
                                     "提示",
                                     "注册成功！",
                                     QMessageBox::Ok);
            //发射信号
            emit send(name,pwd);
        }
        else
        {
            Delay_MSec(2000);
            QMessageBox::information(this,
                                     "提示",
                                     "注册失败！",
                                     QMessageBox::Ok);
        }
    }

    this->close();

}

void Dialog::Sendregisterdata() //注册信息发送
{

    QString name=ui->edit_Name->text();
    QString pwd=ui->edit_Password->text();
    QNetworkRequest request2;
    QEventLoop loop;
    QNetworkAccessManager  m_httpManager;
    QNetworkReply * m_httpReply;
    QNetworkRequest  m_httpRequest;
    QByteArray  m_httpData;
    QJsonDocument m_httpDocum;
    QJsonObject _exampleObject;
    _exampleObject.insert("login_state", "2");

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

}



bool Dialog::registerflagstate()
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
    if(rootObj["login_pass"].toString() == "1")
    {
        //已存在此用户
        return false;
    }
    if(rootObj["login_pass"].toString() == "2")
    {
        return true;
        //注册成功
    }



    file.close();
    qDebug() << "Finished, the code have read to " << FILE_NAME5;
    QObject::disconnect(reply1, SIGNAL(finished()), &loop1, SLOT(quit()));
}



void Dialog::on_pushButton_2_clicked()
{
    this->close();
}
