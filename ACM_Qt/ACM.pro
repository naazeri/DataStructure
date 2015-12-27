#-------------------------------------------------
#
# Project created by QtCreator 2015-12-27T00:00:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ACM
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++14

SOURCES += main.cpp\
        mainwindow.cpp \
    addteam.cpp \
    team.cpp \
    person.cpp

HEADERS  += mainwindow.h \
    addteam.h \
    team.h \
    person.h \
    list.h

FORMS    += mainwindow.ui \
    addteam.ui
