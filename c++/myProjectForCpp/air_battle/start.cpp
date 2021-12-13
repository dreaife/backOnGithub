#include "start.h"
#include "ui_start.h"
#include <QPushButton>

Start::Start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);

    m = new Widget();

    initWindows();

    void(Widget::*send)() = &Widget::failed;
    void(Start::*res)() = &Start::restart;
    connect(m,send,this,res);



}

Start::~Start()
{
    delete ui;
}

void Start::initWindows(){
    //qsrand((unsigned int)time(NULL));

    this->setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    this->setWindowTitle(GAME_TITLE);
    this->setWindowIcon(QIcon(GAME_ICON));

    QPainter painter(this);

    painter.drawPixmap(0,map.map_one_y,map.map_one);
    painter.drawPixmap(0,map.map_two_y,map.map_two);

}

void Start::restart(){
    this->show();

    this->initWindows();
}

void Start::keyPressEvent(QKeyEvent *e){
    if(e->key() == Qt::Key_Escape)
        this->close();
    if(e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return){
        this->m->show();
        this->close();
    }
}
