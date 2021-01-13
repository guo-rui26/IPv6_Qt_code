#include "loginpass.h"

#include <QtCore>
#include <QtNetwork>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QFile>
#include <QJsonObject>

#include <QJsonArray>
#include <QTimer>
#include "mainwindow.h"
const QString URLSTR5 = "http://[2001:da8:270:2021::f9]/login_pass.json";
const QString URLSTR6 = "http://[2001:da8:270:2021::f9]/user_login.json";

const QString FILE_NAME5 = "login_pass.json";
const QString FILE_NAME6 = "user_login.json";
loginPass::loginPass(QWidget *parent) : QWidget(parent)
{

}
loginPass *loginPass::getLoginPassInstence()
{
    static loginPass lp;
    return &lp;
}

void loginPass::onJsonWrite()
{
    QUrl url(URLSTR5);
    QNetworkAccessManager manager;
    QEventLoop loop;
    QTextCodec *codec;
    QNetworkReply *reply;

    qDebug() << "Reading html code form " << URLSTR5;
    reply = manager.get(QNetworkRequest(url));
    //请求结束并下载完成后，退出子事件循环
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    //开启子事件循环
    loop.exec();

    //获取源码，打开文件
    QFile file(FILE_NAME5);
    if( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        qDebug() << "Cannot open the file: " << FILE_NAME5;
    }
    QJsonDocument jsonDocument;
    jsonDocument.setObject(onWriteText());
    file.write(jsonDocument.toJson());
    file.close();
}

QJsonObject loginPass::onWriteText()
{
        QJsonObject jsonObject;
        jsonObject.insert("name","张");
        jsonObject.insert("pwd","123456");

        QJsonArray jsonArray;
        for (int i = 0; i < 10; i++) {
            jsonArray.insert(i,QString::number(i));
        }
        jsonObject.insert("Array",jsonArray);
        // 形式 "num": 52.123
        // double num = 52.123;
        // jsonObject.insert("num", static_cast<QJsonValue>(num));
        return jsonObject;
}

//void loginPass::Sendlogindata()//登录信息发送
//{

//    QNetworkRequest request2;
//    QEventLoop loop;
//    QNetworkAccessManager  m_httpManager;
//    QNetworkReply * m_httpReply;
//    QNetworkRequest  m_httpRequest;
//    QByteArray  m_httpData;
//    QJsonDocument m_httpDocum;
//    QJsonObject _exampleObject;



//    _exampleObject.insert("login_state", "1");
//    _exampleObject.insert("username", "user");
//    _exampleObject.insert("password", "name");
//    //post请求的数据是Json格式。首先创建QJsonObject对象，并插入数据。
//    m_httpDocum.setObject(_exampleObject);
//    m_httpData = m_httpDocum.toJson(QJsonDocument::Compact);
//    QUrl _url(URLSTR6);
//    m_httpRequest.setUrl(_url);
//    // 设置请求的url 注意地址的正确性 之前我就受到了http和https的坑
//    m_httpRequest.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
//    // 设置请求头
//    m_httpReply = m_httpManager.post(m_httpRequest, m_httpData);
//    // post请求
//    QEventLoop _loop;
//    QTimer _timer;
//    QObject::connect(m_httpReply, SIGNAL(finished()), &_loop, SLOT(quit()));
//    QObject:: connect(&_timer, SIGNAL(timeout()), &_loop, SLOT(quit()));
//    // eventloop用于阻塞等待消息，并结合timer进行超时处理
//    _timer.start(1000);
//    _loop.exec();

//}



//bool loginPass::loginflagstate()
//{
//    QUrl url(URLSTR5);
//    QNetworkAccessManager manager1;
//    QEventLoop loop1;
//    QNetworkReply *reply1;

//    qDebug() << "Reading html code form " << URLSTR5;
//    reply1 = manager1.get(QNetworkRequest(url));
//    //请求结束并下载完成后，退出子事件循环
//    QObject::connect(reply1, SIGNAL(finished()), &loop1, SLOT(quit()));
//    //开启子事件循环
//    loop1.exec();

//    //获取源码，打开文件
//    QFile file(FILE_NAME5);
//    if( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
//    {
//        qDebug() << "Cannot open the file: " << FILE_NAME5;
//    }
//    QTextStream out(&file);
//    const QByteArray codeContent = reply1->readAll();


//    QJsonParseError json_error;
//    QJsonDocument jsonDoc(QJsonDocument::fromJson(codeContent, &json_error));

//    if(json_error.error != QJsonParseError::NoError)
//    {
//        qDebug() << "json1 error!";
//    }

//    QJsonObject rootObj = jsonDoc.object();

//    QStringList keys = rootObj.keys();
//    if(rootObj["login_pass"].toString() == "0")
//    {
//        //密码错误
//        return false;
//    }
//    if(rootObj["login_pass"].toString() == "1")
//    {
//        //查无此用户
//        return false;
//    }
//    if(rootObj["login_pass"].toString() == "2")
//    {
//        //登陆成功
//        return true;
//    }




//    file.close();
//    qDebug() << "Finished, the code have read to " << FILE_NAME5;
//    QObject::disconnect(reply1, SIGNAL(finished()), &loop1, SLOT(quit()));
//}




//void loginPass::onJsonWrite()
//{
//    QUrl url(URLSTR5);
//    QNetworkAccessManager manager;
//    QEventLoop loop;
//    QTextCodec *codec;
//    QNetworkReply *reply;

//    qDebug() << "Reading html code form " << URLSTR5;
//    reply = manager.get(QNetworkRequest(url));
//    //请求结束并下载完成后，退出子事件循环
//    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
//    //开启子事件循环
//    loop.exec();

//    //获取源码，打开文件
//    QFile file(FILE_NAME5);
//    if( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
//    {
//        qDebug() << "Cannot open the file: " << FILE_NAME5;
//    }
//    QJsonDocument jsonDocument;
//    jsonDocument.setObject(onWriteText());
//    file.write(jsonDocument.toJson());
//    file.close();
//}

//QJsonObject loginPass::onWriteText()
//{
//        QJsonObject jsonObject;
//        jsonObject.insert("name","张");
//        jsonObject.insert("pwd","123456");

//        QJsonArray jsonArray;
//        for (int i = 0; i < 10; i++) {
//            jsonArray.insert(i,QString::number(i));
//        }
//        jsonObject.insert("Array",jsonArray);
//        // 形式 "num": 52.123
//        // double num = 52.123;
//        // jsonObject.insert("num", static_cast<QJsonValue>(num));
//        return jsonObject;
//}
