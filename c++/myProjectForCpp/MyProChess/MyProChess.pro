#-------------------------------------------------
#
# Project created by QtCreator 2021-06-21T17:58:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyProChess
TEMPLATE = app

CONFIG +=resources_big


SOURCES += main.cpp\
        widget.cpp \
    login.cpp \
    chessbored.cpp \
    chess.cpp \
    robot.cpp \
    register.cpp

HEADERS  += widget.h \
    config.h \
    login.h \
    chessbored.h \
    chess.h \
    robot.h \
    register.h

FORMS    += widget.ui \
    login.ui \
    chessbored.ui \
    register.ui

RESOURCES += \
    res.qrc

CONFIG +=c++11

QT += core gui multimedia
