#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->logButton,&QPushButton::clicked,this,&MainWindow::login);
    connect(ui->cancelButton,&QPushButton::clicked,this,&MainWindow::cancel);
    connect(ui->exitButton,&QPushButton::clicked,this,&MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::login()
{
    QString name = ui->usernameEdit->text();
    QString pass = ui->passwordEdit->text();
    if(name == "admin" && pass== "123456"){
        QMessageBox::information(this,"hint","success");
    }else{
        QMessageBox::warning(this,"warning","the username or password is wrong!");
    }
}

void MainWindow::cancel(){
    ui->usernameEdit->setText("");
    ui->passwordEdit->setText("");
}
