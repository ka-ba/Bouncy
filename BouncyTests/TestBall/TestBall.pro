#-------------------------------------------------
#
# Project created by QtCreator 2018-12-23T00:52:51
#
#-------------------------------------------------

QT       += testlib widgets

QT       -= gui

TARGET = tst_balltest
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_balltest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

# include applications code as lib
# cf. https://wiki.qt.io/How_to_create_a_library_with_Qt_and_use_it_in_an_application
INCLUDEPATH += ../../BouncyCode/
LIBS += -L../../../build-Bouncy-Desktop-Debug/BouncyCode/ -lBouncyCode
