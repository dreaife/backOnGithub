#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("seikai");

    menuBar = new QMenuBar(this);

    menu[0] = new QMenu("home");
    menu[0]->addAction("abstract");

    menu[1] = new QMenu("story");
    menu[1]->addAction("background");

    menu[2] = new QMenu("character");
    menu[2] ->addAction("shinku");

    menu[3] = new QMenu("special");
    menu[3]->addAction("graph");
    menu[3]->addAction("download");

    menu[9] = new QMenu("quit");

    for(int i=0;i<4;i++) menuBar->addMenu(menu[i]);
    menuBar->addMenu(menu[9]);

    menuBar->setGeometry(0,0,this->width(),30);

    void(QMenuBar::*sends)(QAction*) = &QMenuBar::triggered;
    void(MainWindow::*test)(QAction*) = &MainWindow::triggerMenu;

    connect(menuBar,sends,this,test);

}
void MainWindow::triggerMenu(QAction* act){
    //qDebug()<<act;
    if(act->text()=="background")
        qDebug()<<"print story";
    else if(act->text()=="shinku")
        qDebug()<<"shinku suki suki dai suki";
    else if(act->text()=="quit") close();
    else qDebug()<<"erooo!! >_<";
}

MainWindow::~MainWindow()
{
    delete ui;
}
