#include "student.h"

student::student(QObject *parent)
    : QObject{parent}
{

}

void student::studentSay(QString mess){
    qDebug()<<"今天去图书馆学习"<<mess<<"到晚上两点\n";
}

void student::studentSay(){
    qDebug()<<"今天去图书馆学习到晚上两点\n";
}
