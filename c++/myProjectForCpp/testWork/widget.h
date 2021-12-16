#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "map.h"
#include"airplane.h"
#include <QCoreApplication>
#include <QTime>
#include <ctime>
#include <QEventLoop>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void initSence();
    Map map;
    AirPlane air;
    void paintEvent(QPaintEvent *);
    void updatePosition();

    QTimer timer;
    void startGame();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
