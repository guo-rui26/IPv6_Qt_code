#include "json.h"
#include <QDebug>
#include <QFile>
#include <QIODevice>

json::json(QWidget *parent) : QWidget(parent)
{

}

QJsonObject json::loadJson(const QString& filepath)
{
    QFile loadFile(filepath);

    if (!loadFile.open(QIODevice::ReadOnly))
        qDebug() << "Unable to load JSON file";

    QByteArray allData = loadFile.readAll();
    loadFile.close();

    QJsonParseError json_error;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(allData, &json_error));

    if (json_error.error != QJsonParseError::NoError)
        qDebug() << "JSON error!";

    QJsonObject rootObj = jsonDoc.object();
    return rootObj;
}

// NOTE: implicit conversion turns string literal into bool
void json::writeJson(const QString key, bool value)
{
    json.insert(key, value);
}

void json::writeJson(const QString key, int value)
{
    json.insert(key, value);
}

void json::writeJson(const QString key, double value)
{
    json.insert(key, value);
}

// value only support QString
void json::writeJson(const QString key, QString value)
{
    json.insert(key, QString(value));
}

void json::writeJson(const QString key, bool* array, int length)
{
    QJsonArray arr;
    for (int i = 0; i < length; i++)
        arr.append(array[i]);
    json.insert(key, arr);
}

void json::writeJson(const QString key, int* array, int length)
{
    QJsonArray arr;
    for (int i = 0; i < length; i++)
        arr.append(array[i]);
    json.insert(key, arr);
}

void json::writeJson(const QString key, double* array, int length)
{
    QJsonArray arr;
    for (int i = 0; i < length; i++)
        arr.append(array[i]);
    json.insert(key, arr);
}

void json::writeJson(const QString key, QJsonObject object)
{
    json.insert(key, object);
}

bool json::saveJson(const QString& filepath)
{
    QJsonDocument document;
    document.setObject(json);
    QFile file(filepath);

    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Fail to save contents to JSON file";
        return false;
    }

    file.write(document.toJson());

    return true;
}

QString json::toString()
{
    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    QString str(byteArray);
    return str;
}
