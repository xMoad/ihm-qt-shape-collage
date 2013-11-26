#-------------------------------------------------
#
# Project created by QtCreator 2013-11-14T10:46:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tools.cpp \
    dialogpolygon.cpp \
    collage.cpp

HEADERS  += mainwindow.h \
    tools.h \
    collage.h \
    dialogpolygon.h

FORMS    += mainwindow.ui \
    dialogpolygon.ui
