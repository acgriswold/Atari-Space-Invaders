#-------------------------------------------------
#
# Project created by QtCreator 2018-04-03T11:51:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atari_Space_Invaders
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gameplay.cpp \
    tank.cpp \
    bunker.cpp \
    bullet.cpp

HEADERS  += mainwindow.h \
    gameplay.h \
    tank.h \
    bunker.h \
    bullet.h

FORMS    += mainwindow.ui

RESOURCES += \
    sprites.qrc

DISTFILES +=
