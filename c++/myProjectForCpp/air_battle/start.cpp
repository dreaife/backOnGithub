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

    connect(m,&Widget::succes,this,&Start::succes);

}

Start::~Start()
{
    delete ui;
}

void Start::initWindows(){
    //qsrand((unsigned int)time(NULL));
    isSuccess = false;

    this->setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    this->setWindowTitle(GAME_TITLE);
    this->setWindowIcon(QIcon(GAME_ICON));

    textStart = new QLabel("<h1>   飞机大战</h1>\n<h3>press enter to start</h3>",this);
    textStart->setVisible(true);

    textFailed = new QLabel("<h1>    You Failed</h1>\n<h3>press enter to start</h3>",this);
    textFailed->setVisible(false);

    textStart->setGeometry(GAME_WIDTH/2-60,GAME_HEIGHT/2-150,200,60);
    textFailed->setGeometry(GAME_WIDTH/2-60,GAME_HEIGHT/2-150,200,60);
}

void Start::paintEvent(QPaintEvent *){
    QPainter painter(this);

    painter.drawPixmap(0,map.map_one_y,map.map_one);
    painter.drawPixmap(0,map.map_two_y,map.map_two);
}

void Start::restart(){
    this->show();

    m->bgm->stop();

    textFailed->setVisible(true);
    textStart->setVisible(false);

    m->stageNum = 1;
    m->stageUpdate();

    textFailed->setText("<h1>    You Failed!</h1>\n<h3>press enter to start</h3>");
//    this->initWindows();
}

void Start::keyPressEvent(QKeyEvent *e){
    if(e->key() == Qt::Key_Escape)
        this->close();
    if(e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return){
        this->m->show();
        m->isOpen = true;
        m->bgm->play();
        m->initSence();
//        m->startGame();
        this->close();
    }
}

void Start::succes(){
    this->show();
    isSuccess = true;

    m->bgm->stop();

    textFailed->setVisible(true);
    textStart->setVisible(false);

    m->stageNum = 1;
    m->stageUpdate();

    textFailed->setText("<h1>    You Success!</h1>\n<h3>press enter to start</h3>");
}
