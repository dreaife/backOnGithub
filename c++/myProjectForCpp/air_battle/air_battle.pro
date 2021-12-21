#-------------------------------------------------
#
# Project created by QtCreator 2021-06-19T15:50:03
#
#-------------------------------------------------

QT       += core gui
QT      +=core gui multimedia
QT      +=multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = air_battle
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    map.cpp \
    airplane.cpp \
    bullet.cpp \
    enemy.cpp \
    bomb.cpp \
    enemybullet.cpp \
    start.cpp

HEADERS  += widget.h \
    config.h \
    map.h \
    airplane.h \
    bullet.h \
    enemy.h \
    bomb.h \
    enemybullet.h \
    start.h

FORMS    += widget.ui \
    start.ui

RESOURCES += \
    res.qrc

CONFIG +=c++11
CONFIG += RESOURCES_BIG

//Qt6修复
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat
