#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

     this->initSence();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initSence(){
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

void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(0,map.map_one_y,map.map_one);
    painter.drawPixmap(0,map.map_two_y,map.map_two);

    painter.drawPixmap(air.m_x,air.m_y,air.m_plane);

}

void Widget::updatePosition(){
    map.MapMove();
}










