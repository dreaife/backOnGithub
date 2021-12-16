#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    text = new QPlainTextEdit();
    this->setCentralWidget(text);
    this->text->installEventFilter(this);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"Move: ("<<event->x()<<","<<event->y()<<")\n";
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"Press: ("<<event->x()<<","<<event->y()<<")\n";
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"You press : "<<event->key()<<")\n";
}

bool MainWindow::event(QEvent *event){
    if(event->type() == QEvent::KeyPress){
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        if(key->key() == Qt::Key_Space){
             qDebug()<<"You press EVENT : "<<key->key()<<"\n";
             return true;
        }
    }else if(event->type() == QEvent::MouseButtonPress){
        QMouseEvent *mouse = static_cast<QMouseEvent*> (event);
        if(mouse->button() == Qt::LeftButton){
            qDebug()<<"Press EVENT Left Button :( "<<mouse->x()<<","<<mouse->y()<<")\n";
                     return true;
        }else  if(mouse->button() == Qt::RightButton){
            qDebug()<<"Press EVENT Right Button :( "<<mouse->x()<<","<<mouse->y()<<")\n";
                    return true;
    }
        return MainWindow::event(event);
}
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event){
    if(watched == this->text){
        if(event->type() == QEvent::KeyPress){
            QKeyEvent* key = static_cast<QKeyEvent*>(event);
            if(key->key() == Qt::Key_Space){
                 qDebug()<<"You press EVENTILTER :  SPACE \n";
                 return true;
            }
        }else if(event->type() == QEvent::MouseButtonPress){
            QMouseEvent *mouse = static_cast<QMouseEvent*> (event);
            if(mouse->button() == Qt::LeftButton){
                 qDebug()<<"Press EVENTILTER Left Button :( "<<mouse->x()<<","<<mouse->y()<<")\n";
                         return true;
            }else  if(mouse->button() == Qt::RightButton){
                qDebug()<<"Press EVENTILTER Right Button :( "<<mouse->x()<<","<<mouse->y()<<")\n";
                        return true;
        }
            return MainWindow::eventFilter(watched,event);
    }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

