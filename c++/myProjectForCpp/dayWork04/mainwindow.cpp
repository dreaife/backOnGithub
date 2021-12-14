#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    text = new QLabel;
    this->setCentralWidget(text);
    this->installEventFilter(this);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    text->clear();
text->setText(QString("<center><h1>Move: (%1, %2)</h1></center>").arg(QString::number(event->x()),
            QString::number(event->y())));
}
s
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    text->clear();
    text->setText(QString("<center><h1>Press:(%1, %2)</h1></center>").arg(QString::number(event->x()),
                QString::number(event->y())));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QString msg;
    text->clear();
    msg.push_back(QString("<center><h1>You press %1.</h1></center>").arg(event->key()));
    text->setText(msg);
}

bool MainWindow::event(QEvent *event){
    if(event->type() == QEvent::KeyPress){
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        if(key->key() == Qt::Key_Space){
            text->clear();
             text->setText(QString("<center><h1>You press  EVENT space.</h1></center>"));
             return true;
        }
    }else if(event->type() == QEvent::MouseButtonPress){
        QMouseEvent *mouse = static_cast<QMouseEvent*> (event);
        if(mouse->button() == Qt::LeftButton){
            text->clear();
             text->setText(QString("<center><h1>Press EVENT Left Button  (%1, %2)</h1></center>").arg(mouse->x()).arg(mouse->y()));
                     return true;
        }else  if(mouse->button() == Qt::RightButton){
            text->clear();
            text->setText(QString("<center><h1>Press EVENT Right Button  (%1, %2)</h1></center>").arg(mouse->x()).arg(mouse->y()));
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
                text->clear();
                 text->setText(QString("<center><h1>You press  EVENTILTER space.</h1></center>"));
                 return false;
            }
        }else if(event->type() == QEvent::MouseButtonPress){
            QMouseEvent *mouse = static_cast<QMouseEvent*> (event);
            if(mouse->button() == Qt::LeftButton){
                text->clear();
                 text->setText(QString("<center><h1>Press EVENTILTER Left Button  (%1, %2)</h1></center>").arg(mouse->x()).arg(mouse->y()));
                         return true;
            }else  if(mouse->button() == Qt::RightButton){
                text->clear();
                text->setText(QString("<center><h1>Press EVENTILTER Right Button  (%1, %2)</h1></center>").arg(mouse->x()).arg(mouse->y()));
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

