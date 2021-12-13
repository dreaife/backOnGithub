#-------------------------------------------------
#
# Project created by QtCreator 2021-06-16T17:42:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = day02
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    story.cpp

HEADERS  += mainwindow.h \
    story.h

FORMS    += mainwindow.ui

CONFIG  +=c++11

RESOURCES += \
    background.qrc
