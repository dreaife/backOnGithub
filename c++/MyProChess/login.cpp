#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    w = new Widget();

    M = new Register();

    initPlayersData();

    void(Login::*send)(int) = &Login::success;
    void(Widget::*succes)(int) = &Widget::success;

    connect(this,send,w,succes);

    void(Register::*sen)() = &Register::accept;
    void(Login::*acc)() = &Login::accept;

    connect(M,sen,this,acc);

    this->setWindowIcon(QIcon(ICON_PATH));
    this->setWindowTitle("用户登录");
}

void Login::accept(){
    M->close();
    this->initPlayersData();
    this->show();

}

void Login::paintEvent(QPaintEvent *){
    QPainter painter(this);
    back.load(BACKGROUND_PATH_1);

    painter.drawPixmap(-280,-260,back);
}

void Login::initPlayersData(){
    QFile file("./members.dat");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QDataStream in(&file);
    in >> members;
    file.close();
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginGame_clicked()
{
    QString a = ui->username->text();
    QString b = ui->password->text();

    for(int i=0;i<members[0].num;i++)
    if(a==members[i].username&&b==members[i].password){
        qDebug()<<"accept";
        emit success(i);
        w->bgm->play();
        this->close();
        return;
    }
    qDebug()<<"failed";
    ui->username->clear();
    ui->password->clear();
    QMessageBox::warning(this,"警告","用户名或密码错误！",QMessageBox::Yes);
}

void Login::on_NewMemb_clicked()
{
    M->show();
    this->close();
}

void Login::on_Quit_clicked()
{
    this->close();
}
