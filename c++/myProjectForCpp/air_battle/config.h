#ifndef CONFIG_H
#define CONFIG_H

#define GAME_WIDTH 512
#define GAME_HEIGHT 768
#define MAP_MOVE_SPEED 2
#define GAME_RATE 10
#define AIR_MOVE_SPEED 20
#define BULLET_MOVE_SPEED 5
#define BULLET_NUM 30
#define BULLET_INTERVAL 10
#define ENEMY_BULLET_MOVE_SPEED 4
#define ENEMY_BULLET_NUM 30
#define ENEMY_BULLET_INTERVAL 40
#define ENEMY_MOVE_SPEED 3
#define ENEMY_NUM 20
#define ENEMY_INTERVAL 40
#define BOMB_MAX 20
#define BOMB_NUM 7
#define BOMB_INTERVAL 20

#define GAME_TITLE "飞机大战 v1.0"
#define GAME_ICON "://res/FAVOICON.png"
#define MAP_PATH ":/res/img_bg_level_%1.jpg"
#define AIR_PATH ":/res/hero2.png"
#define BULLET_PATH ":/res/bullet_%1.png"
#define ENEMY_BULLET_PATH ":/res/bullet_%1.png"
#define ENEMY_PATH ":/res/img-plane_%1.png"
#define BOMB_PATH ":/res/bomb-%1.png"
#define SOUND_BACKGROUND "://res/bg.wav"
#define SOUND_BOMB "://res/bomb.wav"

#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QRect>
#include <QEvent>
#include <QKeyEvent>
#include <QLabel>

//代码中引入头文件
#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
#include <QtCore5Compat>
#endif

#endif // CONFIG_H
