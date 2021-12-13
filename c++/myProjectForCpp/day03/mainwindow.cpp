#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QPushButton>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tools = new QToolBar(this);

    tools->addAction("add");
    tools->addAction("submit");
    tools->addAction("quit");

    tools->setGeometry(0,0,this->width(),30);

    void(QToolBar::*send)(QAction*) = &QToolBar::actionTriggered;
    void(MainWindow::*get)(QAction*) = &MainWindow::trigerTool;

    connect(tools,send,this,get);


    QPushButton* btn = new QPushButton("click it",this);
    btn->move(200,200);

    connect(btn,&QPushButton::clicked,this,&MainWindow::showDiag);

    QPushButton* bbt = new QPushButton("guess",this);
    bbt->move(300,300);

    connect(bbt,&QPushButton::clicked,this,&MainWindow::getText);

    QPushButton* b = new QPushButton("warning",this);
    b->move(100,100);

    connect(b,&QPushButton::clicked,this,&MainWindow::Pwarn);
}

void MainWindow::trigerTool(QAction *act){
    if(act->text()=="quit")
        close();
    else
        qDebug()<<act->text();
}

void MainWindow::getText(){
    QMessageBox* pt = new QMessageBox();
    pt->setText("gg");
    pt->setInformativeText("shinku shinku shinku");

    pt->setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    pt->setDefaultButton(QMessageBox::Cancel);

    int rec = pt->exec();
    if(rec==QMessageBox::Cancel)
        qDebug()<<"cancel";
}

void MainWindow::showDiag(){
    QDialog* quit = new QDialog(this);
    quit->setWindowTitle("qualify");
    QPushButton* pp = new QPushButton("suprise",quit);
    QPushButton* re = new QPushButton("return",quit);
    quit->resize(500,300);
    pp->move(100,150);
    re->move(200,150);
    connect(re,&QPushButton::clicked,quit,&QPushButton::close);
    connect(pp,&QPushButton::clicked,this,&QPushButton::close);
    quit->exec();
}

void MainWindow::Pwarn(){
    QMessageBox* pp = new QMessageBox();
    pp->warning(this,"warning","stop!!");
}

void MainWindow::success(QString *username){
    this->show();
    this->ui->username->setText(*username);
}

MainWindow::~MainWindow()
{
    delete ui;
}
