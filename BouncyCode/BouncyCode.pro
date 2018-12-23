#-------------------------------------------------
#
# Project created by QtCreator 2018-12-19T22:29:32
#
#-------------------------------------------------

QT       += widgets

QT       -= gui

TARGET = BouncyCode
TEMPLATE = lib
# g++ 4.9 only fully supports c++11, and only parts of c++14
CONFIG += staticlib c++11

SOURCES += bouncycode.cpp \
    ball.cpp

HEADERS += bouncycode.h \
    ball.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
