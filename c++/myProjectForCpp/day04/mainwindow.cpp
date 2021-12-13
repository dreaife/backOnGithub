#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QEvent>
#include <QKeyEvent>
#include <QPainter>
#include <QPixmap>
#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

/*    btn = new QPushButton("123",this);
    btn->move(200,200);
    btn->installEventFilter(this);

    text = new QTextEdit(this);
    text->move(100,100);
    text->resize(60,40);
    text->installEventFilter(this);
    */


}

MainWindow::~MainWindow()
{
    delete ui;
}

/*bool MainWindow::event(QEvent *e){
    if(e->type()==QEvent::MouseButtonPress){
        qDebug()<<"鼠标点击";
    }else if(e->type()==QEvent::Move){
        qDebug()<<"鼠标移动";
    }
    return 0;
}
*/
bool MainWindow::eventFilter(QObject *obj, QEvent *event){
    if(obj == btn){
        if(event->type() == QEvent::Move){
            qDebug()<<"Move!!!Move!!";
            return true;
        }
        else return false;
    }else if(obj == text){
        if(event->type() == QEvent::KeyPress){
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            qDebug()<<"Press the key "<< keyEvent->key();
            return true;
        }
        return false;
    }else
        return QMainWindow::eventFilter(obj,event);
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    setWindowTitle(tr("painter"));

    painter.drawLine(0,0,100,100);

    painter.setPen(Qt::red);

    painter.drawRect(100,100,150,150);

    painter.setPen(QPen(Qt::green,5));
    painter.setBrush(Qt::blue);

    painter.drawEllipse(100,100,150,50);

    QPixmap picture(":/add/runa.jpg");

    QPainter painters(this);
    painters.drawPixmap(100,100,picture);



}
