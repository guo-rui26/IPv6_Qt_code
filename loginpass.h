#ifndef LOGINPASS_H
#define LOGINPASS_H

#include <QWidget>
#include <QJsonObject>
class loginPass : public QWidget
{
    Q_OBJECT
public:
    explicit loginPass(QWidget *parent = nullptr);
    static loginPass *getLoginPassInstence();  //静态的获取数据库对象的函数


signals:

public slots:
    void onJsonWrite();
    QJsonObject onWriteText();

//    void Sendlogindata();
//    void Sendregisterdata();
//    bool loginflagstate();
//    void registerflagstate();
};

#endif // LOGINPASS_H
