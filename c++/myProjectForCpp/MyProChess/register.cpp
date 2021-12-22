#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(ICON_PATH));

    initPlayersData();

    this->setWindowTitle("用户注册");

}

Register::~Register()
{
    delete ui;
}

void Register::paintEvent(QPaintEvent *){
    QPainter painter(this);
    back.load(BACKGROUND_PATH_1);

    painter.drawPixmap(-280,-260,back);
}

void Register::initPlayersData(){
    QFile file("./members.dat");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QDataStream in(&file);
    in >> members;
    file.close();
}
void Register::on_DisRegister_clicked()
{
    emit this->accept();
}

void Register::clearText(){
    ui->username->clear();
    ui->password->clear();
    ui->passwordConfine->clear();
}

void Register::saveGamePlayerData(){
    QFile writeFile("./members.dat");
    writeFile.open(QIODevice::WriteOnly);
    QDataStream out(&writeFile);
    out << members;
    writeFile.close();
}

void Register::on_regiserConfine_clicked()
{
    QString a = ui->username->text();
    QString b = ui->password->text();
    QString c = ui->passwordConfine->text();
    if(b!=c){
        QMessageBox::warning(this,"注意","密码与确认密码不符");
        this->clearText();
        return;
    }
    if(checkP(members,a)){
        QMessageBox::warning(this,"注意","该用户名已注册");
        this->clearText();
        return;
    }else{
        members[members[0].num].username=a;
        members[members[0].num].password=b;
        members[members[0].num].num=members[0].num;
        members[0].num++;
        saveGamePlayerData();
        QMessageBox::information(this,"恭喜","用户注册成功");
        this->clearText();
        emit accept();
        return;
    }
}
