#include "mainwindow_menu.h"
#include "ui_mainwindow_menu.h"
#include "listwidget.h"
#include <QString>
#include <QDebug>
#include <QComboBox>

#include <QMessageBox>

#include "database.h"
#include <QtCore>
#include <QtNetwork>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QFile>
#include <QJsonObject>
#include <QPushButton>
#include <QJsonArray>
#include <QTimer>

#include <QTextBrowser>
#include <QTextStream>
#include <QAbstractScrollArea>
#include <QTextCursor>
#include <QStringList>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>

#include "chart.h"
#include "chartwindow.h"
QT_CHARTS_USE_NAMESPACE

//网页地址
const QString URLSTR = "http://[2001:da8:270:2021::f9]/car_data_2.json";
const QString URLSTR1 = "http://[2001:da8:270:2021::f9]/car_data_1.json";
const QString URLSTR3 = "http://[2001:da8:270:2021::f9]/stoporder.json";
const QString URLSTR5 = "http://[2001:da8:270:2021::f9]/login_pass.json";
const QString URLSTR6 = "http://[2001:da8:270:2021::f9]/user_login.json";
//储存网页代码的文件
const QString FILE_NAME = "car_data_2.json";
const QString FILE_NAME1 = "car_data_1.json";
const QString FILE_NAME3 = "stoporder.json";
const QString FILE_NAME5 = "login_pass.json";
const QString FILE_NAME6 = "user_login.json";
int flag1=0;
MainWindow_menu::MainWindow_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_menu)
{
    ui->setupUi(this);
    this->setFixedSize(500,700);
    ui->comboBox->addItem("请选择车辆");
    ui->comboBox->addItem("车辆1");
    ui->comboBox->addItem("车辆2");


//    listwidget_ = new ListWidget(this);
//    this->setCentralWidget(listwidget_);
//    listwidget_->setGeometry(100, 100, 600, 260);

    int idex = ui->comboBox->currentIndex();
    QString text = ui->comboBox->currentText();
    qDebug() << idex <<' ' <<text.toUtf8().data();
    init();

    timer = new QTimer(this);
    timer->setSingleShot(false);
//    connect(ui->comboBox, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),ui->ButtonYes,SLOT(click));

//    connect(ui->ButtonYes, SIGNAL(clicked()),this, SLOT(static_cast<void(QComboBox::*)(int)>(&QComboBox::on_comboBox_currentIndexChanged)));
//     connect(timer, SIGNAL(timeout()),ui->ButtonYes,&QPushButton::click());
    //    connect(timer, SIGNAL(timeout()), this, SLOT(static_cast<void(QComboBox::*)(int)>(&QComboBox::on_comboBox_currentIndexChanged)));

    connect(ui->comboBox,SIGNAL(currentIndexChanged()),this,SLOT(on_ButtonYes_clicked()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged()),ui->ButtonDisplay,SLOT(on_ButtonDisplay_clicked()));

    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(on_timer_timeout()));

    //退出窗口
    connect(ui->ButtonCancel,&QPushButton::clicked,timer, &QTimer::stop);
//    connect(ui->comboBox, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
//                 [=](const QString &text){display(); });

}

void MainWindow_menu::on_timer_timeout()
{
    //定时器中断响
//    QTime curTime=QTime::currentTime(); //获取当前时间
//    int va=ui->progressBar->value();
//    va++;
//    if (va>100)
//        va=0;
//    ui->progressBar->setValue(va);
}

MainWindow_menu::~MainWindow_menu()
{
    delete ui;
}

void MainWindow_menu::figure()
{
//    m_chartView = new QChartView(m_chart,this);//画布
//       m_chart = m_chartView->chart();//画笔
}

//void MainWindow_menu::showFileContents()
//{

//    QTimer *timer3;

//    QUrl url(URLSTR);
//    QNetworkAccessManager manager;
//    QEventLoop loop;
//    QTextCodec *codec;
//    QNetworkReply *reply;

//    qDebug() << "Reading html code form " << URLSTR;
//    reply = manager.get(QNetworkRequest(url));
//    //请求结束并下载完成后，退出子事件循环
//    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
//    //开启子事件循环
//    loop.exec();

//    //获取源码，打开文件
//    QFile file(FILE_NAME);
//    if( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
//    {
//        qDebug() << "Cannot open the file: " << FILE_NAME;
//    }
//    QTextStream stream(&file);
//    QJsonParseError json_error;
//    const QByteArray codeContent = reply->readAll();

//    QJsonDocument jsonDoc(QJsonDocument::fromJson(codeContent, &json_error));

//    if(json_error.error != QJsonParseError::NoError)
//    {
//        qDebug() << "json error!";
//    }

//    QJsonObject rootObj = jsonDoc.object();

//    //初始时加上首行说明
//    if(lastReadRowNums==0){
//        qDebug()<<"初始lastReadRowNums:"<<lastReadRowNums;
//        ui->textBrowser->append("------------------------------------------------------------------");
//    }


//    while(!stream.atEnd()){
//        QString line=stream.readLine();
//        if (line.startsWith("#") || line.startsWith("variables"))
//            continue;
//        url.append("  "+line.trimmed());//trimmed():Returns a string that has whitespace removed from the start and the end.
//    }

//    int len=url.size();
//    ui->textBrowser->append(url.at(lastReadRowNums++));
//    qDebug()<<"lastReadRowNums"<<lastReadRowNums;

//    //杀掉定时器
//    if(lastReadRowNums>len-1){//此处数目设置为所读文件的最大行数
//        qDebug()<<" stop timerTXT!";
//        timer3->stop();
//        }
// }

//槽函数

void MainWindow_menu::on_comboBox_currentIndexChanged(const QString &arg1)
{

}




void MainWindow_menu::on_ButtonYes_clicked()
{


    QTime qtimeObj_delay = QTime::currentTime();
    int time_sec = qtimeObj_delay.second();
    time_sec = time_sec + 2;
    while (time_sec != qtimeObj_delay.second()) qtimeObj_delay = QTime::currentTime();

    QTimer *timer1;



    timer1 = new QTimer(this);
    timer->setSingleShot(false);

         if(ui->comboBox->currentIndex()==1)
         {
             flag1=1;
            qDebug()<<"flag1=  "<<flag1<<endl;
             connect(timer, SIGNAL(timeout()), this, SLOT(display()));
             connect(timer, SIGNAL(timeout()), this, SLOT(qtimeSlot()));
//             disconnect(timer1, SIGNAL(timeout()), this, SLOT(display1()));



         }
         else if(ui->comboBox->currentIndex()==2)
         {
            flag1=2;
            qDebug()<<"flag1=  "<<flag1<<endl;
             connect(timer, SIGNAL(timeout()), this, SLOT(display()));
             connect(timer, SIGNAL(timeout()), this, SLOT(qtimeSlot()));
//            disconnect(timer1, SIGNAL(timeout()), this, SLOT(display()));


         }
         else
         {

           connect(timer, SIGNAL(timeout()), this, SLOT(display()));
           connect(timer, SIGNAL(timeout()), this, SLOT(qtimeSlot()));

//             disconnect(timer1, SIGNAL(timeout()), this, SLOT(display()));

         }

            timer->start(1000);
}

//时间函数
void MainWindow_menu::qtimeSlot()
{
    QTime qtimeObj = QTime::currentTime();
    QString strTime = qtimeObj.toString("ap h:m");
    strTime.prepend("  时间: ");
    QDate qdateObj = QDate::currentDate();
   // QString strDate = qdateObj.toString("dddd, MMMM d, yyyy"); //星期、月份、天、年
    QString strDate = qdateObj.toString("dddd yyyy-MM-dd"); //星期、月份、天、年
    strDate.prepend("日期: ");

    strDate.append(strTime);
//    ui->textEdit->setPlainText(strDate);
    ui->textEdit->append(" ");
    ui->textEdit->append(" ");
    ui->textEdit->append(strDate);

}


void MainWindow_menu::on_ButtonCancel_clicked()
{
    this->close();
}



void MainWindow_menu::on_ButtonSure_clicked()
{
    QTimer *timer2;
    timer2 = new QTimer(this);
//    qDebug()<<qHash(arg1);
    timer2->setSingleShot(true);
    if(ui->comboBox->currentText()=="车辆1")
    {

        display();
       // connect(timer2, SIGNAL(timeout()), this, SLOT(qtimeSlot()));
    }
    else if(ui->comboBox->currentText()=="车辆2")
    {

        display();
      //  connect(timer2, SIGNAL(timeout()), this, SLOT(qtimeSlot()));
    }
    timer2->start(1000);
}

void MainWindow_menu::recUsrname(QString name)
{
//    QString str = QString("欢迎进入智能码头集装箱管控平台! %1").arg(name);
//    ui->label->setText(str);
}


void MainWindow_menu::display()
{

    if(ui->comboBox->currentIndex()==2)
    {
        flag1=2;
        QUrl url(URLSTR);
        QEventLoop loop;
        QTextCodec *codec;
        QNetworkReply *reply;
        QNetworkAccessManager manager;

        qDebug() << "Reading html code form " << URLSTR;
        reply = manager.get(QNetworkRequest(url));
        //请求结束并下载完成后，退出子事件循环
        QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        //开启子事件循环
        loop.exec();

        //获取源码，打开文件
        QFile file(FILE_NAME);
        if( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
        {
            qDebug() << "Cannot open the file: " << FILE_NAME;
        }
        QTextStream out(&file);
        const QByteArray codeContent = reply->readAll();


        QJsonParseError json_error;
        QJsonDocument jsonDoc(QJsonDocument::fromJson(codeContent, &json_error));

        if(json_error.error != QJsonParseError::NoError)
        {
            qDebug() << "json error!";
        }

        QJsonObject rootObj = jsonDoc.object();

        QStringList keys = rootObj.keys();
    //    for(int i = 0; i < keys.size(); i++)
    //    {
    //        qDebug() << "key" << i << " is:" << keys.at(i);
    //    }

    //    ui->textEdit->setText(code);

        //因为是预先定义好的JSON数据格式，所以这里可以这样读取



        QString str = "<table border='1' cellpadding='10' >"
                            " <tr>   <td>车辆物理标称</td>     <td>车辆数据信息</td>    </tr> "
                            " <tr>   <td> 车辆编号 </td>      <td>"+rootObj["car_id"].toString()+"</td>    </tr> "
                            " <tr>   <td> 车辆x坐标 </td>     <td>"+rootObj["car_location_x"].toString()+"</td>    </tr> "
                            " <tr>   <td> 车辆y坐标 </td>     <td>"+rootObj["car_location_y"].toString()+"</td>    </tr> "
                            " <tr>   <td> 车辆出发地 </td>    <td>"+rootObj["car_start"].toString()+"</td>    </tr> "
                            " <tr>   <td> 车辆目的地 </td>    <td>"+rootObj["car_dest"].toString()+"</td>    </tr> "
                            " <tr>   <td> 车辆电池电量 </td>  <td>"+rootObj["car_ele"].toString()+"</td>    </tr> "
                            " <tr>   <td> 车辆状态 </td>     <td>"+rootObj["car_state"].toString()+"</td>    </tr> "
                            " <tr>   <td> 车辆速度 </td>     <td>"+rootObj["car_veolcity"].toString()+"</td>    </tr> "
                            " <tr>   <td> 车辆位置 </td>     <td>"+rootObj["car_location_num"].toString()+"</td>    </tr> "
                            "</align:center>"
                            "</table> ";
//       ui->textEdit->insertHtml(str);
        ui->textEdit->setAlignment(Qt::AlignCenter);

         ui->textEdit->setHtml(str);



//        ui->textEdit->setPlainText("车辆编号: " + rootObj["car_id"].toString());
////        ui->textEdit->append(" ");
//        ui->textEdit->append("车辆x坐标: " + rootObj["car_location_x"].toString());
////        ui->textEdit->append(" ");
//        ui->textEdit->append("车辆y坐标: " + rootObj["car_location_y"].toString());
////        ui->textEdit->append(" ");
//        ui->textEdit->append("车辆出发地: " + rootObj["car_start"].toString());
////        ui->textEdit->append(" ");
//        ui->textEdit->append("车辆目的地: " + rootObj["car_dest"].toString());
////        ui->textEdit->append(" ");
//        ui->textEdit->append("车辆电池电量: " + rootObj["car_ele"].toString());
////        ui->textEdit->append(" ");
//        ui->textEdit->append("车辆状态: " + rootObj["car_state"].toString());
////        ui->textEdit->append(" ");
//        ui->textEdit->append("车辆速度: " + rootObj["car_veolcity"].toString());
////        ui->textEdit->append(" ");
//        ui->textEdit->append("车辆位置: " + rootObj["car_location_num"].toString());


           qDebug() << "car_id is:" << rootObj["car_id"].toString();
           qDebug() << "car_location_x is:" << rootObj["car_location_x"].toString();
           qDebug() << "car_location_y is:" << rootObj["car_location_y"].toString();

        file.close();
        qDebug() << "Finished, the code have read to " << FILE_NAME;
        QObject::disconnect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    }
    if(ui->comboBox->currentIndex()==1)
    {
        flag1=1;
        QUrl url1(URLSTR1);
        QEventLoop loop;
        QTextCodec *codec;
         QNetworkAccessManager manager1;
        QNetworkReply *reply1;

        qDebug() << "Reading html code form " << URLSTR1;
        reply1 = manager1.get(QNetworkRequest(url1));
        //请求结束并下载完成后，退出子事件循环
        QObject::connect(reply1, SIGNAL(finished()), &loop, SLOT(quit()));
        //开启子事件循环
        loop.exec();

        //获取源码，打开文件
        QFile file(FILE_NAME1);
        if( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
        {
            qDebug() << "Cannot open the file: " << FILE_NAME1;
        }
        QTextStream out(&file);
        const QByteArray codeContent = reply1->readAll();


        QJsonParseError json_error;
        QJsonDocument jsonDoc(QJsonDocument::fromJson(codeContent, &json_error));

        if(json_error.error != QJsonParseError::NoError)
        {
            qDebug() << "json error!";
        }

        QJsonObject rootObj = jsonDoc.object();

        QStringList keys = rootObj.keys();
    //    for(int i = 0; i < keys.size(); i++)
    //    {
    //        qDebug() << "key" << i << " is:" << keys.at(i);
    //    }



    //    ui->textEdit->setText(code);

        //因为是预先定义好的JSON数据格式，所以这里可以这样读取


        QString str = "<table border='1' cellpadding='10'>"
                            " <tr>   <td>车辆物理标称</td>     <td>车辆数据信息</td>    </tr> "
                            " <tr>   <td> 车辆编号 </td>      <td>"+rootObj["car_id"].toString()+"</td>    </tr> "
                            " <tr>   <td> 车辆x坐标 </td>     <td>"+rootObj["car_location_x"].toString()+"</td>    </tr> "
                            " <tr>   <td> 车辆y坐标 </td>     <td>"+rootObj["car_location_y"].toString()+"</td>    </tr> "
                            " <tr>   <td> 车辆出发地 </td>    <td>"+rootObj["car_start"].toString()+"</td>    </tr> "
                            " <tr>   <td> 车辆目的地 </td>    <td>"+rootObj["car_dest"].toString()+"</td>    </tr> "
                            " <tr>   <td> 车辆电池电量 </td>  <td>"+rootObj["car_ele"].toString()+"</td>    </tr> "
                            " <tr>   <td> 车辆状态 </td>     <td>"+rootObj["car_state"].toString()+"</td>    </tr> "
                            " <tr>   <td> 车辆速度 </td>     <td>"+rootObj["car_veolcity"].toString()+"</td>    </tr> "
                            " <tr>   <td> 车辆位置 </td>     <td>"+rootObj["car_location_num"].toString()+"</td>    </tr> "
                            "</table> ";
//       ui->textEdit->insertHtml(str);
       ui->textEdit->setHtml(str);


//        ui->textEdit->setPlainText("车辆编号: " + rootObj["car_id"].toString());
//        ui->textEdit->append("车辆x坐标: " + rootObj["car_location_x"].toString());
//        ui->textEdit->append("车辆y坐标: " + rootObj["car_location_y"].toString());
//        ui->textEdit->append("车辆出发地: " + rootObj["car_start"].toString());
//        ui->textEdit->append("车辆目的地: " + rootObj["car_dest"].toString());
//        ui->textEdit->append("车辆电池电量: " + rootObj["car_ele"].toString());
//        ui->textEdit->append("车辆状态: " + rootObj["car_state"].toString());
//        ui->textEdit->append("车辆速度: " + rootObj["car_veolcity"].toString());
//        ui->textEdit->append("车辆位置: " + rootObj["car_location_num"].toString());


           qDebug() << "car_id is:" << rootObj["car_id"].toString();
           qDebug() << "car_location_x is:" << rootObj["car_location_x"].toString();
           qDebug() << "car_location_y is:" << rootObj["car_location_y"].toString();

        file.close();
        qDebug() << "Finished, the code have read to " << FILE_NAME1;
        QObject::disconnect(reply1, SIGNAL(finished()), &loop, SLOT(quit()));
    }

    if(ui->comboBox->currentIndex()==0)
    {
        flag1=3;
        qDebug()<<"请选择车辆："<<endl;
         ui->textEdit->setPlainText("等待车辆的选择：");
    }

}

void MainWindow_menu::on_ButtonTerminal_clicked()
{
    SendTerminal();
}

void MainWindow_menu::init()
{

            QUrl url(URLSTR3);
            QNetworkAccessManager manager1;
            QEventLoop loop1;
            QTextCodec *codec1;
            QNetworkReply *reply1;

            qDebug() << "Reading html code form " << URLSTR3;
            reply1 = manager1.get(QNetworkRequest(url));
            //请求结束并下载完成后，退出子事件循环
            QObject::connect(reply1, SIGNAL(finished()), &loop1, SLOT(quit()));
            //开启子事件循环
            loop1.exec();

            //获取源码，打开文件
            QFile file(FILE_NAME3);
            if( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
            {
                qDebug() << "Cannot open the file: " << FILE_NAME3;
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
            for(int i = 0; i < keys.size(); i++)
            {
                qDebug() << "key" << i << " is:" << keys.at(i);
            }
            file.close();
            qDebug() << "Finished, the code have read to stoporder" << FILE_NAME3;

}

void MainWindow_menu::SendTerminal()
{
    QNetworkRequest request2;
    QEventLoop loop;
    QNetworkAccessManager  m_httpManager;
    QNetworkReply * m_httpReply;
    QNetworkRequest  m_httpRequest;
    QByteArray  m_httpData;
    QJsonDocument m_httpDocum;
    QJsonObject _exampleObject;
    _exampleObject.insert("stoporder", "1");
    //post请求的数据是Json格式。首先创建QJsonObject对象，并插入数据。
    m_httpDocum.setObject(_exampleObject);
    m_httpData = m_httpDocum.toJson(QJsonDocument::Compact);
    QUrl _url(URLSTR3);
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


void MainWindow_menu::SendStart()
{


    QNetworkRequest request2;
    QEventLoop loop;
    QNetworkAccessManager  m_httpManager;
    QNetworkReply * m_httpReply;
    QNetworkRequest  m_httpRequest;
    QByteArray  m_httpData;
    QJsonDocument m_httpDocum;
    QJsonObject _exampleObject;
    _exampleObject.insert("stoporder", "0");
    //post请求的数据是Json格式。首先创建QJsonObject对象，并插入数据。
    m_httpDocum.setObject(_exampleObject);
    m_httpData = m_httpDocum.toJson(QJsonDocument::Compact);
    QUrl _url(URLSTR3);
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


void MainWindow_menu::on_ButtonStart_clicked()
{
    SendStart();
}





void MainWindow_menu::on_ButtonDisplay_clicked()
{


         ChartWindow *cw = new ChartWindow();
         cw->show();
//    QMainWindow window;
//    chart *chart1 = new chart;
//    chart1->setTitle("Dynamic spline chart");
//    chart1->legend()->hide();
//    chart1->setAnimationOptions(QChart::AllAnimations);
//    QChartView chartView(chart1);
//    chartView.setRenderHint(QPainter::Antialiasing);

//    this->setCentralWidget(&chartView);

//    window.setCentralWidget(&chartView);
//    window.resize(400, 300);
//    window.show();
//    system("pause");





//    if(ui->comboBox->currentIndex()==2)
//    {
//        QUrl url(URLSTR);
//        QEventLoop loop;
//        QTextCodec *codec;
//        QNetworkReply *reply;
//        QNetworkAccessManager manager;

//        qDebug() << "Reading html code form " << URLSTR;
//        reply = manager.get(QNetworkRequest(url));
//        //请求结束并下载完成后，退出子事件循环
//        QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
//        //开启子事件循环
//        loop.exec();

//        //获取源码，打开文件
//        QFile file(FILE_NAME);
//        if( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
//        {
//            qDebug() << "Cannot open the file: " << FILE_NAME;
//        }
//        QTextStream out(&file);
//        const QByteArray codeContent = reply->readAll();


//        QJsonParseError json_error;
//        QJsonDocument jsonDoc(QJsonDocument::fromJson(codeContent, &json_error));

//        if(json_error.error != QJsonParseError::NoError)
//        {
//            qDebug() << "json error!";
//        }

//        QJsonObject rootObj = jsonDoc.object();

//        QStringList keys = rootObj.keys();

//        //因为是预先定义好的JSON数据格式，所以这里可以这样读取



//           qDebug() << "car_id is:" << rootObj["car_id"].toString();
//           qDebug() << "car_location_x is:" << rootObj["car_location_x"].toString();
//           qDebug() << "car_location_y is:" << rootObj["car_location_y"].toString();

//        file.close();
//        qDebug() << "Finished, the code have read to " << FILE_NAME;
//        QObject::disconnect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
//    }
//    if(ui->comboBox->currentIndex()==1)
//    {
//        QUrl url1(URLSTR1);
//        QEventLoop loop;
//        QTextCodec *codec;
//         QNetworkAccessManager manager1;
//        QNetworkReply *reply1;

//        qDebug() << "Reading html code form " << URLSTR1;
//        reply1 = manager1.get(QNetworkRequest(url1));
//        //请求结束并下载完成后，退出子事件循环
//        QObject::connect(reply1, SIGNAL(finished()), &loop, SLOT(quit()));
//        //开启子事件循环
//        loop.exec();

//        //获取源码，打开文件
//        QFile file(FILE_NAME1);
//        if( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
//        {
//            qDebug() << "Cannot open the file: " << FILE_NAME1;
//        }
//        QTextStream out(&file);
//        const QByteArray codeContent = reply1->readAll();


//        QJsonParseError json_error;
//        QJsonDocument jsonDoc(QJsonDocument::fromJson(codeContent, &json_error));

//        if(json_error.error != QJsonParseError::NoError)
//        {
//            qDebug() << "json error!";
//        }

//        QJsonObject rootObj = jsonDoc.object();

//        QStringList keys = rootObj.keys();
//    //    for(int i = 0; i < keys.size(); i++)
//    //    {
//    //        qDebug() << "key" << i << " is:" << keys.at(i);
//    //    }



//    //    ui->textEdit->setText(code);

//        //因为是预先定义好的JSON数据格式，所以这里可以这样读取

//        ui->textEdit->append("车辆x坐标: " + rootObj["car_location_x"].toString());
//        ui->textEdit->append("车辆y坐标: " + rootObj["car_location_y"].toString());



//           qDebug() << "car_id is:" << rootObj["car_id"].toString();
//           qDebug() << "car_location_x is:" << rootObj["car_location_x"].toString();
//           qDebug() << "car_location_y is:" << rootObj["car_location_y"].toString();

//        file.close();
//        qDebug() << "Finished, the code have read to " << FILE_NAME1;
//        QObject::disconnect(reply1, SIGNAL(finished()), &loop, SLOT(quit()));
//    }

//    if(ui->comboBox->currentIndex()==0)
//    {
//        qDebug()<<"请选择车辆："<<endl;
//         ui->textEdit->setPlainText("等待车辆的选择：");
//    }

}
