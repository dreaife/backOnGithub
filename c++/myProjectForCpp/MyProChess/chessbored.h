#ifndef CHESSBORED_H
#define CHESSBORED_H

#include <QWidget>
#include "config.h"
#include <QPainter>
#include <QRect>
#include <QPixmap>
#include <QMouseEvent>
#include "robot.h"
#include "chess.h"
#include <QTimer>
#include <QTime>
#include <QTimerEvent>
#include <QMessageBox>
#include <QPixmap>

namespace Ui {
class chessBored;
}

class chessBored : public QWidget
{
    Q_OBJECT



public:
    explicit chessBored(QWidget *parent = 0);
    ~chessBored();

    void pause();

    void initGameSence();
    int counts;

    void paintEvent(QPaintEvent *);

    QPushButton* backMenu;
    QPushButton* reStart;

    Robot rob;

    int PlayerOne;
    int PlayerTwo;

    QSoundEffect* pressSound;
    QSoundEffect* winSound;

    Chess virtualPoint;
    QTimer timer;

    void startGame();
    //void update();

    int W,LW,R;
    int times;
    int dropI,dropJ;

    bool chessDropEnable;

    int max(int a,int b);
    int min(int a,int b);

    bool gameModel;
    int GameLevel;

    int chessOnBored[16][16];

    bool isGameOver(int x,int y);
    bool isGameDead();

    Chess blackChess;
    Chess whiteChess;

    QPixmap chessBoreds;
    QPixmap bg;

    void mouseMoveEvent(QMouseEvent *);

    void mousePressEvent(QMouseEvent *);

    void sleep_msec(int msec);

    void robotChess();
    void GameLevelDefine(QString*);

    //void timerEvent(QTimerEvent*);

signals:
    void backToGameMenu();
    void chessPress();
    void gameEnd(int e);

private slots:
    void backMenuClicked();
    void chessPressDo();

private:
    Ui::chessBored *ui;

};

#endif // CHESSBORED_H
