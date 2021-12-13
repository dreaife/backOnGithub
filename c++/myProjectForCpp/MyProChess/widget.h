#ifndef WIDGET_H
#define WIDGET_H

#include "config.h"
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QDebug>
#include "chessbored.h"
#include "register.h"
#include <QPixmap>
#include <QPainter>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    QPushButton *pve;
    QPushButton *score;
    QPushButton *level;

    QPushButton* prim;
    QPushButton* midd;
    QPushButton* prof;
    QPushButton* returnBack;

    QPushButton* leaveGame;

    chessBored* w;
    Register* pt;

    QPixmap back;

    int gameLevel;

    int memberList;
    gamePlayer members[GAME_PLAYER_NUM];
    void initPlayersData();

    void initScense();
    void initGameButton();
    void hideGameButton();

    void initPlayerScore();
    void hidePlayerScore();
    void showPlayerScore();

    void paintEvent(QPaintEvent *);
signals:
    void gameTrigger(QString* e);
public slots:
    void success(int e);
    void gameEnd(int e);
    void gameCheck();
    void gameBack();
    void gameStart(QString* gameLev);

    void gameTriggerOne();
    void gameTriggerTwo();
    void gameTriggerThree();

    void gameBackToMenu();

    void gamePlayerListShow();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
