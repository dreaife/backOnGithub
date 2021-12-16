#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     this->initSence();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initSence(){
    srand((unsigned int)time(NULL));

    this->setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    this->setWindowTitle(GAME_TITLE);
    this->setWindowIcon(QIcon(GAME_ICON));

    this->startGame();
    this->timer.setInterval(GAME_RATE);
}

void Widget::startGame(){
    this->timer.start();
    connect(&timer,&QTimer::timeout,[=](){
        this->updatePosition();
        this->update();
    });
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(0,map.map_one_y,map.map_one);
    painter.drawPixmap(0,map.map_two_y,map.map_two);

}

void MainWindow::updatePosition(){
    map.MapMove();
}










