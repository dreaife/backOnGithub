# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyProChess
TEMPLATE = app

CONFIG +=resources_big


SOURCES += main.cpp\
    chess.cpp \
    chessbored.cpp \
    login.cpp \
    register.cpp \
    robot.cpp \
        widget.cpp \
    login.cpp \
    register.cpp

HEADERS  += widget.h \
    chess.h \
    chessbored.h \
    config.h \
    config.h \
    login.h \
    login.h \
    register.h \
    register.h \
    robot.h

FORMS    += widget.ui \
    login.ui \
    register.ui

CONFIG +=c++11

QT += core gui multimedia

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc
