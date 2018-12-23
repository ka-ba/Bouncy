#-------------------------------------------------
#
# Project created by QtCreator 2018-12-19T22:30:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BouncyMain
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        bouncywindow.cpp

HEADERS  += bouncywindow.h

FORMS    += bouncywindow.ui

# include applications code as lib
# cf. https://wiki.qt.io/How_to_create_a_library_with_Qt_and_use_it_in_an_application
INCLUDEPATH += ../BouncyCode/
LIBS += -L../../build-Bouncy-Desktop-Debug/BouncyCode/ -lBouncyCode
