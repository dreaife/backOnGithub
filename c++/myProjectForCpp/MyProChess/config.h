#ifndef CONFIG_H
#define CONFIG_H

#define MENU_HEIGHT 500
#define MENU_WIDTH 500

#define GAME_HEIGHT 700
#define GAME_WIDTH 800
#define GAME_BORED_LINE_WIDTH 40
#define GAME_BORED_WIDTH 30
#define GAME_SCAN_RANGE 20
#define GAME_CHESS_RANGE 20

#define GAME_RATE 1000
#define GAME_PLAYER_NUM 100

#define VIRTUAL_CHESS_SIZE 5
#define VIRTUAL_POINT_PATH ":/res/virtualPoint.png"
#define CHESS_BORED_PATH ":/res/chessBored.jpg"
#define ICON_PATH ":/res/FAVORITE.ico"
#define BLACK_CHESS_PATH ":/res/black.png"
#define WHITE_CHESS_PATH ":/res/white.png"
#define BACKGROUND_PATH ":/res/bg.png"
#define BACKGROUND_PATH_1 ":/res/bg.jpg"
#define BACKGROUND_PATH_2 ":/res/backGround5.png"

#define SOUND_START ":/sound/start.wav"
#define SOUND_PRESS ":/sound/press.wav"
#define SOUND_WIN ":/sound/press.wav"

#define CHESS_NUM 256

#define WEIGHT_ZERO 0
#define WEIGHT_ONE 3
#define WEIGHT_TWE 8
#define WEIGHT_THREE 15
#define WEIGHT_FOUR 30

#define WEIGHT_ZERO_PRIM 0
#define WEIGHT_ONE_PRIM 1
#define WEIGHT_TWE_PRIM 2
#define WEIGHT_THREE_PRIM 3
#define WEIGHT_FOUR_PRIM 4

#include <QPushButton>
#include <QMediaPlayer>
#include <QThread>
#include <QDebug>
#include <QVector>
#include <QString>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <QApplication>
#include <QCoreApplication>
#include <QFile>
#include <QByteArray>
#include <QSound>

const int levelRank[20] = {5,10,15,20,30,50,70,100,130,160,200,250,300,350,400,500,600,700,800,900};

struct cP{
    int x;
    int y;
};

struct gamePlayer{
    QString username;
    QString password;
    int level;
    int exp;
    int num;
    int bestScore;
    bool isLevelLimit(){
        if(exp>=levelRank[level-1]) return true;
        else return false;
    }

    void levelUp(){
        if(isLevelLimit()){
            exp=exp-levelRank[level-1];
            level++;
        }
    }
    friend bool check(gamePlayer t[],QString user,QString pass){
        for(int i=0;i<t[0].num;i++){
            QString a = t[i].username;
            QString b = t[i].password;
            if(user == a&& pass == b)
                return true;
        }
        return false;
    }

    friend bool checkP(gamePlayer t[],QString user){
        for(int i=0;i<t[0].num;i++){
            QString a = t[i].username;
            if(user == a)
                return true;
        }
        return false;
    }

    gamePlayer():username("admin"),password("123456"),level(0),exp(0),num(1),bestScore(0){}
    friend QDataStream& operator<<(QDataStream &out, const gamePlayer t[]){
        for(int i=0;i<t[0].num;i++)
            out << t[i].username <<t[i].password <<t[i].level <<t[i].exp <<t[i].num<<t[i].bestScore;
        return out;
    }

    friend QDataStream& operator>>(QDataStream &in, gamePlayer t[]){
        int a,b,c,f;
        QString d,e;
        in >>d>>e>>a>>b>>c>>f;
        t[0].username=d;t[0].password=e;
        t[0].level=a;t[0].exp=b;t[0].num=c;t[0].bestScore=f;
        for(int i=1;i<t[0].num;i++){
            in >>d>>e>>a>>b>>c>>f;
            t[i].username=d;t[i].password=e;
            t[i].level=a;t[i].exp=b;t[i].num=c;t[i].bestScore=f;
        }
        return in;
    }
};

#endif // CONFIG_H
