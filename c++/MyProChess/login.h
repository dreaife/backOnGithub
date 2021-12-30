#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "widget.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QPainter>
#include <QPixmap>
#include "register.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

    Widget* w;
    Register* M;

    QPixmap back;

    gamePlayer members[GAME_PLAYER_NUM];

    void initPlayersData();

    void paintEvent(QPaintEvent*);

signals:
    void success(int e);

public slots:
    void accept();

private slots:
    void on_loginGame_clicked();

    void on_NewMemb_clicked();

    void on_Quit_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
