#include "chartwindow.h"
#include "ui_chartwindow.h"
#include "QtCharts/QChart"
#include "QLineSeries"
#include "QValueAxis"
#include "QTimer"
#include "QTime"
#include "QList"
#include "qmath.h"
#include "QPointF"
#include "QDebug"
#include <QVBoxLayout>
#include "mainwindow_menu.h"
//#include <QtCharts/QChartGlobal>
#include "QChartView"

#include <QtNetwork>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QFile>
#include <QJsonObject>
#include <QPushButton>
#include <QJsonArray>
#include <QTimer>
#include <QAbstractAnimation>
#include <QDebug>
#include <QPen>
#include <QtCharts/QLineSeries>//线系列

QT_CHARTS_USE_NAMESPACE
#include <fstream>
#include <QTime>
#include <QThread>
const QString URLSTR = "http://[2001:da8:270:2021::f9]/car_data_2.json";
const QString URLSTR1 = "http://[2001:da8:270:2021::f9]/car_data_1.json";
const QString FILE_NAME = "car_data_2.json";
const QString FILE_NAME1 = "car_data_1.json";
ChartWindow::ChartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChartWindow)
{
      ui->setupUi(this);
      open = true;
      qDebug()<<" "<<endl;
      extern int flag1;
      qDebug()<<" "<<flag1<<endl;
      qDebug()<<" "<<endl;
      timer2 = new QTimer;
      timer2->setSingleShot(false);
      connect(timer2, SIGNAL(timeout()), ui->btn_open, SLOT(on_btn_open_clicked()));
      timer2->start(1000);
      connect(ui->btn_close,&QPushButton::clicked,timer2, &QTimer::stop);
}
void ChartWindow::on_btn_open_clicked()
{
    if(flag1==1)
    {
        timer2->disconnect(timer2, SIGNAL(timeout()), this, SLOT(getData()));
        timer2->setSingleShot(false);
        timer2->connect(timer2, SIGNAL(timeout()), this, SLOT(getData1()));
        timer2->start(1000);
    }

    if(flag1==2)
    {
        timer2->disconnect(timer2, SIGNAL(timeout()), this, SLOT(getData1()));
        timer2->setSingleShot(false);
        connect(timer2, SIGNAL(timeout()), this, SLOT(getData()));
        timer2->start(1000);
    }
    if(flag1==3)
    {
        timer2->setSingleShot(false);
        timer2->start(1000);
    }
}





ChartWindow::~ChartWindow()
{
    delete ui;
}

void ChartWindow::getData()
{
    QVector <int> array;

        qDebug()<<"车辆--2--绘图"<<endl;
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

        //因为是预先定义好的JSON数据格式，所以这里可以这样读取

          double valx=rootObj["car_location_x"].toString().toDouble(); //val=123.45  //QString 转 double
          double valy=rootObj["car_location_y"].toString().toDouble();

          QFile file_2("C:\\Users\\GMH\\Desktop\\QT\\56ba2915\\cc3\\LoginAndRegistration\\data.txt");
          if(file_2.open(QIODevice::WriteOnly | QIODevice::Text))
             {
                 QTextStream out(&file_2);

                 for(int i=0; i<array.size(); i++)
                 {
                     out<<array[rootObj["car_location_x"].toString().toDouble()]<<" ";
                     out<<array[rootObj["car_location_y"].toString().toDouble()]<<" ";
                 }
             }

          file_2.close();

          //添加标题头
          QChart *chart = new QChart();
          chart->setTheme(QChart::ChartThemeQt);
          chart->setTitle("车辆动态位置坐标显示");
          chart->setMargins(QMargins(10, 10, 10, 10));
          QScatterSeries *scatterSeries = new QScatterSeries();
          scatterSeries->setName("车俩坐标");
          scatterSeries->setPointLabelsFormat("(@xPoint, @yPoint)");
          scatterSeries->setMarkerSize(10);
          scatterSeries->setPointLabelsVisible();
          scatterSeries->append(rootObj["car_location_x"].toString().toDouble(),rootObj["car_location_y"].toString().toDouble());
          QValueAxis *xAxis = new QValueAxis();
          QValueAxis *yAxis = new QValueAxis();

          xAxis->setRange(0, 1000);
          yAxis->setRange(0, 1200);

          // 轴标题设置
          xAxis->setTitleText(QStringLiteral("车辆x坐标"));
          yAxis->setTitleText(QStringLiteral("车辆y坐标"));
          xAxis->setTitleFont(QFont("宋体"));
          QBrush brush;
          brush.setStyle(Qt::SolidPattern);
          brush.setColor(Qt::red);
          xAxis->setTitleBrush(brush);

          // 轴标签设置
          xAxis->setLabelFormat("%.1f");
          xAxis->setLabelsAngle(45);
          xAxis->setLabelsColor(Qt::blue);
          xAxis->setLabelsEditable(true);

          // 轴线和刻度线设置
          xAxis->setTickCount(11);
          QPen pen;
          pen.setStyle(Qt::SolidLine);
          pen.setColor(Qt::red);
          xAxis->setLinePen(pen);
          xAxis->setLineVisible(true);
          xAxis->setLinePenColor(Qt::blue);
          // 主网格线设置
          xAxis->setGridLineVisible(true);
          xAxis->setGridLineColor(Qt::black);

          // 次刻度和次网格线设置
          xAxis->setMinorTickCount(5);
          xAxis->setMinorGridLineColor(Qt::red);
          chart->addSeries(scatterSeries);
          chart->addAxis(xAxis, Qt::AlignBottom);
          chart->addAxis(yAxis, Qt::AlignLeft);

          scatterSeries->attachAxis(xAxis);
          scatterSeries->attachAxis(yAxis);
          ui->viewxy->setChart(chart);
          ui->viewxy->setRubberBand(QChartView::RectangleRubberBand);
          ui->viewxy->setRenderHint(QPainter::Antialiasing, true);
          qDebug() <<valx;
          qDebug() <<valy;

          qDebug() << "car_id is:" << rootObj["car_id"].toString().toUtf8().data();
          qDebug() << "car_location_x is:" << rootObj["car_location_x"].toString().toUtf8().data();
          qDebug() << "car_location_y is:" << rootObj["car_location_y"].toString().toUtf8().data();

          file.close();
          qDebug() << "Finished, the code have read to " << FILE_NAME;
          QObject::disconnect(reply, SIGNAL(finished()), &loop, SLOT(quit()));


}

void ChartWindow::getData1()
{
    QVector <int> array;
    qDebug()<<"车辆--1--绘图"<<endl;
    QUrl url(URLSTR1);
    QEventLoop loop;
    QTextCodec *codec;
    QNetworkReply *reply1;
    QNetworkAccessManager manager1;

    qDebug() << "Reading html code form " << URLSTR1;
    reply1 = manager1.get(QNetworkRequest(url));
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

    //因为是预先定义好的JSON数据格式，所以这里可以这样读取

    double valx=rootObj["car_location_x"].toString().toDouble(); //val=123.45  //QString 转 double
    double valy=rootObj["car_location_y"].toString().toDouble();

    QFile file_2("C:\\Users\\GMH\\Desktop\\QT\\56ba2915\\cc3\\LoginAndRegistration\\data.txt");
    if(file_2.open(QIODevice::WriteOnly | QIODevice::Text))
       {
             QTextStream out(&file_2);

             for(int i=0; i<array.size(); i++)
             {
                 out<<array[rootObj["car_location_x"].toString().toDouble()]<<" ";
                 out<<array[rootObj["car_location_y"].toString().toDouble()]<<" ";
             }
       }

    file_2.close();

    //添加标题头
    QChart *chart = new QChart();
    chart->setTheme(QChart::ChartThemeQt);
    chart->setTitle("车辆动态位置坐标显示");
    chart->setMargins(QMargins(10, 10, 10, 10));

    QScatterSeries *scatterSeries = new QScatterSeries();
    scatterSeries->setName("车俩坐标");
    scatterSeries->setPointLabelsFormat("(@xPoint, @yPoint)");
    scatterSeries->setMarkerSize(10);
    scatterSeries->setPointLabelsVisible();

    scatterSeries->append(rootObj["car_location_x"].toString().toDouble(),rootObj["car_location_y"].toString().toDouble());

    QValueAxis *xAxis = new QValueAxis();
    QValueAxis *yAxis = new QValueAxis();

    xAxis->setRange(0, 1000);
    yAxis->setRange(0, 1200);

    // 轴标题设置
    xAxis->setTitleText(QStringLiteral("车辆x坐标"));
    yAxis->setTitleText(QStringLiteral("车辆y坐标"));
    xAxis->setTitleFont(QFont("宋体"));
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    xAxis->setTitleBrush(brush);
    // 轴标签设置
    xAxis->setLabelFormat("%.1f");
    xAxis->setLabelsAngle(45);
    xAxis->setLabelsColor(Qt::blue);
    xAxis->setLabelsEditable(true);
    // 轴线和刻度线设置
    xAxis->setTickCount(11);
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::red);
    xAxis->setLinePen(pen);
    xAxis->setLineVisible(true);
    xAxis->setLinePenColor(Qt::blue);

    // 主网格线设置
    xAxis->setGridLineVisible(true);
    xAxis->setGridLineColor(Qt::black);

    // 次刻度和次网格线设置
    xAxis->setMinorTickCount(5);
    xAxis->setMinorGridLineColor(Qt::red);

    chart->addSeries(scatterSeries);

    chart->addAxis(xAxis, Qt::AlignBottom);
    chart->addAxis(yAxis, Qt::AlignLeft);

    scatterSeries->attachAxis(xAxis);
    scatterSeries->attachAxis(yAxis);

    ui->viewxy->setChart(chart);
    ui->viewxy->setRubberBand(QChartView::RectangleRubberBand);
    ui->viewxy->setRenderHint(QPainter::Antialiasing, true);

    qDebug() <<valx;
    qDebug() <<valy;

    qDebug() << "car_id is:" << rootObj["car_id"].toString().toUtf8().data();
    qDebug() << "car_location_x is:" << rootObj["car_location_x"].toString().toUtf8().data();
    qDebug() << "car_location_y is:" << rootObj["car_location_y"].toString().toUtf8().data();

    file.close();
    qDebug() << "Finished, the code have read to " << FILE_NAME1;
    QObject::disconnect(reply1, SIGNAL(finished()), &loop, SLOT(quit()));

}

void ChartWindow::on_btn_close_clicked()
{
    open = false;
    t = 0;
    killTimer(Timer);
    timer2->connect(timer2,SIGNAL(timeout()),this,SLOT(Stop()));
    timer2->stop();
    this->close();

}

void ChartWindow::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == Timer)
    {
        if(t >= max_X)
        {
            max_X +=1; //扩大

        }
        qreal rd;
        qreal y = 0;
        qsrand(QTime::currentTime().second());
        rd =(qrand() % 100);
        y = rd +5;
        t++;
    }
}
