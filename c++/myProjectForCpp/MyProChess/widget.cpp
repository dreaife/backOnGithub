#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    pve = new QPushButton();
    score = new QPushButton();
    level = new QPushButton();

    prim = new QPushButton();
    midd = new QPushButton();
    prof = new QPushButton();
    returnBack = new QPushButton();

    leaveGame = new QPushButton();

    w = new chessBored();
    pt = new Register();

    initScense();

    connect(leaveGame,&QPushButton::clicked,this,&Widget::close);

    connect(pve,&QPushButton::clicked,this,&Widget::gameCheck);

    connect(returnBack,&QPushButton::clicked,this,&Widget::gameBack);

    connect(prim,&QPushButton::clicked,this,&Widget::gameTriggerOne);
    connect(midd,&QPushButton::clicked,this,&Widget::gameTriggerTwo);
    connect(prof,&QPushButton::clicked,this,&Widget::gameTriggerThree);

    connect(w,&chessBored::backToGameMenu,this,&Widget::gameBackToMenu);

    void(Widget::*send)(QString*) = &Widget::gameTrigger;
    void(Widget::*acc)(QString*) = &Widget::gameStart;

    connect(this,send,this,acc);

    void(chessBored::*sco)(int) = &chessBored::gameEnd;
    void(Widget::*getIt)(int) = &Widget::gameEnd;
    connect(w,sco,this,getIt);

    connect(this->level,&QPushButton::clicked,this,[=](){
        QMessageBox::information(this,"等级","您当前等级为"+QString::number(members[memberList].level));
    });

    connect(this->score,&QPushButton::clicked,this,&Widget::gamePlayerListShow);

}

void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    back.load(BACKGROUND_PATH_2);

    painter.drawPixmap(0,0,back);
    painter.drawPixmap(452,0,back);
}

void Widget::gameEnd(int e){
    qDebug()<<e;
    if(e>members[memberList].bestScore){
        pt->members[memberList].bestScore = e;
    }
    pt->members[memberList].exp+=3*this->gameLevel;
    qDebug()<<pt->members[memberList].exp;
    pt->members[memberList].levelUp();
    this->pt->saveGamePlayerData();
    initPlayerScore();
}

void Widget::gamePlayerListShow(){
    prim->setVisible(false);
    midd->setVisible(false);
    prof->setVisible(false);
    returnBack->setVisible(true);

    pve->setVisible(false);
    score->setVisible(false);
    level->setVisible(false);

    showPlayerScore();

    ui->user->setVisible(false);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::gameTriggerOne(){
    this->gameLevel = 1;
    QString a = "prim";
    emit gameTrigger(&a);
}

void Widget::gameTriggerTwo(){
    this->gameLevel = 2;
    QString a = "midd";
    emit gameTrigger(&a);
}

void Widget::gameTriggerThree(){
    this->gameLevel = 3;
    QString a = "prof";
    emit gameTrigger(&a);
}

void Widget::initScense(){
    this->setFixedHeight(MENU_HEIGHT);
    this->setFixedWidth(MENU_WIDTH);

    this->setWindowTitle("五子棋");
    this->setWindowIcon(QIcon(ICON_PATH));

    initPlayerScore();

    prim->setParent(this);
    prim->setText("初级");
    prim->move(200,100);


    midd->setParent(this);
    midd->setText("中级");
    midd->move(200,200);

    prof->setParent(this);
    prof->setText("高级");
    prof->move(200,300);

    pve->setParent(this);
    pve->setText("人机对战");
    pve->move(200,100);
    pve->setVisible(true);


    score->setParent(this);
    score->setText("排行榜");
    score->move(200,200);
    score->setVisible(true);

    level->setParent(this);
    level->setText("等级");
    level->move(200,300);
    level->setVisible(true);

    returnBack->setParent(this);
    returnBack->setText("返回");
    returnBack->move(200,400);

    leaveGame->setParent(this);
    leaveGame->setText("退出");
    leaveGame->move(400,35);
    leaveGame->resize(60,40);

    this->hideGameButton();
}

void Widget::initPlayersData(){
    QFile file("members.dat");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QDataStream in(&file);
    in >> members;
    file.close();
}

void Widget::success(int e){
    this->show();

    qDebug()<<members[e].bestScore;
    memberList = e;
    initPlayersData();

    this->ui->user->setText("用户:"+members[e].username);
}

void Widget::initGameButton(){
    prim->setVisible(true);
    midd->setVisible(true);
    prof->setVisible(true);
    returnBack->setVisible(true);

    pve->setVisible(false);
    score->setVisible(false);
    level->setVisible(false);
}

void Widget::hideGameButton(){
    prim->setVisible(false);
    midd->setVisible(false);
    prof->setVisible(false);
    returnBack->setVisible(false);

    pve->setVisible(true);
    score->setVisible(true);
    level->setVisible(true);

    ui->user->setVisible(true);
}

void Widget::gameCheck(){
    this->initGameButton();
}

void Widget::gameBack(){
    this->initScense();
}

void Widget::initPlayerScore(){
    initPlayersData();
    int temp[5]={0,0,0,0,0};
    int ti=0,ts=0,p=0;
    for(int i=0;i<5;i++){
        for(int j=1;j<members[0].num;j++){
            for(int k=0;k<5;k++) if(temp[k]==j) p=1;
            if(p) {p=0;continue;}
            if(members[j].bestScore>=ts){
                ts=members[j].bestScore;
                ti = j;
            }
        }
        temp[i] = ti;
    }

    qDebug()<<members[0].num;
    for(int i=0;i<5;i++)
        for(int j=i+1;j<5;j++)
            if(temp[i]==temp[j]) temp[j]=0;
    for(int i=0;i<5;i++) qDebug()<<temp[i];
    if(temp[0]) ui->mem1->setText("1."+members[temp[0]].username+"  "+QString::number(members[temp[0]].bestScore));
    if(temp[1]) ui->mem2->setText("2."+members[temp[1]].username+"  "+QString::number(members[temp[1]].bestScore));
    if(temp[2]) ui->mem3->setText("3."+members[temp[2]].username+"  "+QString::number(members[temp[2]].bestScore));
    if(temp[3]) ui->mem4->setText("4."+members[temp[3]].username+"  "+QString::number(members[temp[3]].bestScore));
    if(temp[4]) ui->mem5->setText("5."+members[temp[4]].username+"  "+QString::number(members[temp[4]].bestScore));

    ui->mem1->move(150,70);
    ui->mem2->move(150,140);
    ui->mem3->move(150,210);
    ui->mem4->move(150,280);
    ui->mem5->move(150,350);

    hidePlayerScore();
}

void Widget::hidePlayerScore(){
    ui->mem1->setVisible(false);
    ui->mem2->setVisible(false);
    ui->mem3->setVisible(false);
    ui->mem4->setVisible(false);
    ui->mem5->setVisible(false);
}

void Widget::showPlayerScore(){
    ui->mem1->setVisible(true);
    ui->mem2->setVisible(true);
    ui->mem3->setVisible(true);
    ui->mem4->setVisible(true);
    ui->mem5->setVisible(true);
}

void Widget::gameStart(QString* gameLev){
    this->close();
    QSound::play(SOUND_START);
    w->GameLevelDefine(gameLev);
    w->show();
    w->counts = 999;
}

void Widget::gameBackToMenu(){
    this->show();

    this->initScense();
}
