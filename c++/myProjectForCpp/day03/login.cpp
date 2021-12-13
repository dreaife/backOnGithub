#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <QDebug>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    m = new MainWindow();

    void(Login::*send)(QString*) = &Login::success;
    void(MainWindow::*successes)(QString*) = &MainWindow::success;

    connect(this,send,m,successes);
}

Login::~Login()
{
    delete ui;
}

void Login::on_exitLogin_clicked()
{
    this->close();
}


void Login::on_LoginLib_clicked()
{
    QString a = ui->username->text();
    QString b = ui->password->text();

    if(a=="123456"&&b=="123456"){
        qDebug()<<"accept";
        emit success(&a);
        this->close();
    }else{
        qDebug()<<"failed";
        ui->username->clear();
        ui->password->clear();
        QMessageBox::warning(this,"警告","用户名或密码错误！",QMessageBox::Yes);
    }
}
