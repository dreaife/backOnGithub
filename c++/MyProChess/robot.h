#ifndef ROBOT_H
#define ROBOT_H

#include <QWidget>
#include "config.h"
#include <QMouseEvent>
#include <ctime>

class Robot : public QWidget
{
    Q_OBJECT
public:
    explicit Robot(QWidget *parent = 0);

    int w[16][16];

    int ComType;
    int PerType;

    int robNum;
    int perNum;

    void getType(int x);

    cP getPointPrim(int cb[][16]);
    cP getPointMidd(int cb[][16]);
    cP getPointProf(int cb[][16]);

    int calPoint(int t);
    int calPointPrim(int t);

signals:

public slots:

};

#endif // ROBOT_H
