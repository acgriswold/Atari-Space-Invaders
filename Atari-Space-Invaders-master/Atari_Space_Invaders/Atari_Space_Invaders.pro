#-------------------------------------------------
#
# Project created by QtCreator 2018-04-03T11:51:26
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atari_Space_Invaders
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gameplay.cpp \
    tank.cpp \
    bunker.cpp \
    bullet.cpp \
    tile.cpp \
    squad.cpp \
    invader.cpp \
    bullet_enemy.cpp \
    jelly.cpp

HEADERS  += mainwindow.h \
    gameplay.h \
    tank.h \
    bunker.h \
    bullet.h \
    tile.h \
    squad.h \
    invader.h \
    bullet_enemy.h \
    jelly.h

FORMS    += mainwindow.ui

RESOURCES += \
    sprites.qrc \
    sounds.qrc

DISTFILES +=
