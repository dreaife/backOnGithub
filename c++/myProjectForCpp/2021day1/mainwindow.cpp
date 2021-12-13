#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("this");

    DataBaseLoad();
    initNum();
}

void MainWindow::DataBaseLoad(){
        db = QSqlDatabase::addDatabase("QODBC");
        db.setHostName("127.0.0.1");
        db.setPort(3306);
        db.setDatabaseName("mysql");
        db.setUserName("dreaife");
        db.setPassword("20011223hqs12");
        bool ok = db.open();
        if (ok){
            QMessageBox::information(this, "infor", "success");
        }
        else {
            QMessageBox::information(this, "infor", db.lastError().text());
        }
}

void MainWindow::initNum(){
    QSqlQuery dbselect(db);num = 0;
    QString sql = QString("select * from USER;");
    dbselect.exec(sql);
    while(dbselect.next()) num= qMax(num,dbselect.value(0).toInt());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_selectButton_clicked()
{
    QSqlQuery dbselect(db);
    QString sql = QString("select * from USER;");
    dbselect.exec(sql);
    QString res;
    while(dbselect.next()){
        res += (dbselect.value(0).toString()+"\t");
        res+= (dbselect.value(1).toString()+"\t");
        res += (dbselect.value(2).toString()+"\t");
        res += (dbselect.value(3).toString()+"\n");
    }ui->showArea->setText(res);
}

void MainWindow::on_createButton_clicked()
{
    QSqlQuery dbinsert(db);
    QString sql = QString("insert into USER values('%1','%2','%3',%4);").arg(QString::number(num+1)).arg(ui->usernameEdit->text()).arg(ui->passwordEdit->text())
            .arg(ui->scoreEdit->text().isEmpty()?"0":ui->scoreEdit->text());
    bool ok = dbinsert.exec(sql);
    if(ok){
        num ++;
        ui->usernameEdit->clear();
        ui->passwordEdit->clear();
        ui->scoreEdit->clear();
        ui->showArea->clear();
        ui->showArea->setText("create account successfully!\n");
    }else{
        ui->showArea->clear();
        ui->showArea->setText("create account failed!\n");
    }
}


void MainWindow::on_exitButton_clicked()
{
    this->close();
}


void MainWindow::on_updateButton_clicked()
{
    QSqlQuery dbupdate(db);
    QString sql = QString("update USER set US = %3 where UN = '%1' AND UP ='%2';")
            .arg(ui->usernameEdit->text())
            .arg(ui->passwordEdit->text())
            .arg(ui->scoreEdit->text().isEmpty()?"0":ui->scoreEdit->text());
    bool ok = dbupdate.exec(sql);
    if(ok){
        ui->usernameEdit->clear();
        ui->passwordEdit->clear();
        ui->scoreEdit->clear();
        ui->showArea->clear();
        ui->showArea->setText("update account successfully!\n");
    }else{
        ui->showArea->clear();
        ui->showArea->setText("update account failed!\n");
    }
}


void MainWindow::on_deleteButton_clicked()
{
    QSqlQuery dbdelete(db);
    QString sql = QString("delete from USER  where UN = '%1' AND UP ='%2';")
            .arg(ui->usernameEdit->text())
            .arg(ui->passwordEdit->text());
    bool ok = dbdelete.exec(sql);
    if(ok){
        initNum();
        ui->usernameEdit->clear();
        ui->passwordEdit->clear();
        ui->showArea->clear();
        ui->showArea->setText("delete account successfully!\n");
    }else{
        ui->showArea->clear();
        ui->showArea->setText("delete account failed!\n");
    }
}

