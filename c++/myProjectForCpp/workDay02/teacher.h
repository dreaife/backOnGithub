#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>
#include <QString>

class teacher : public QObject
{
    Q_OBJECT
public:
    explicit teacher(QObject *parent = nullptr);

signals:
    void teacherSay(QString mess);
    void teacherSay();

};

#endif // TEACHER_H
