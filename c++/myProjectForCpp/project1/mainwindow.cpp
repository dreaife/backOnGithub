#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QWidget>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton * b1 = new QPushButton("p1",this);
    QPushButton* b2 = new QPushButton("p2",this);

    b2->move(100,100);

    int m=10;

    connect(b1,&QPushButton::clicked,this,[m]()mutable{
        m=20;qDebug()<<m;
    });
    QWidget::connect(b2,&QPushButton::clicked,this,[=](){
        qDebug()<<m;
    });

    qDebug()<<m;
}
void MainWindow::dd(){
    qDebug()<<"11111";
}

void MainWindow::hangs(){
    emit dd();
    qDebug()<<"1321321";
}

MainWindow::~MainWindow()
{
    delete ui;
}
