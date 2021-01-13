#ifndef CHART_H
#define CHART_H

#include <QMainWindow>
#include <QtCharts/QChart>
#include <QtCore/QTimer>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class chart : public QChart
{
    Q_OBJECT
public:
//    explicit chart(QWidget *parent = nullptr);
    chart(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);
    virtual ~chart();

signals:

private:
    QTimer m_timer;
    QSplineSeries *m_series;
    QStringList m_titles;
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;
    qreal m_step;
    qreal m_x;
    qreal m_y;

public slots:
    void handleTimeout();
};

#endif // CHART_H
