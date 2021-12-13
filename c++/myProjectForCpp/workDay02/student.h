#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QDebug>

class student : public QObject
{
    Q_OBJECT
public:
    explicit student(QObject *parent = nullptr);

public slots:
    void studentSay(QString mess);
    void studentSay();

signals:

};

#endif // STUDENT_H
