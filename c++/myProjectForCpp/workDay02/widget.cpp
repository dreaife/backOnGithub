#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    teacher *teach = new teacher(this);
    student *stud = new student(this);

    void (teacher::*tea)(QString) = &teacher::teacherSay;
    void (teacher::*tea2)(void) = &teacher::teacherSay;

    void (student::*stu)(QString) = &student::studentSay;
    void (student::*stu2)(void) = &student::studentSay;

    connect(teach,tea,stud,stu);
    connect(teach,tea2,stud,stu2);

    emit teach->teacherSay("数据结构");
    emit teach->teacherSay();
}

Widget::~Widget()
{
    delete ui;
}

