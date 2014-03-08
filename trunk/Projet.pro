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
    collage.cpp \
    photos.cpp \
    photoswizardpage.cpp \
    wizard.cpp \
    shape.cpp \
    shapewizardpage.cpp \
    sizes.cpp \
    rotationmax.cpp \
    sizeswizardpage.cpp

HEADERS  += mainwindow.h \
    tools.h \
    collage.h \
    dialogpolygon.h \
    photos.h \
    photoswizardpage.h \
    wizard.h \
    shape.h \
    shapewizardpage.h \
    sizes.h \
    rotationmax.h \
    sizeswizardpage.h

FORMS    += mainwindow.ui \
    dialogpolygon.ui \
    photos.ui \
    photoswizardpage.ui \
    wizard.ui \
    shape.ui \
    shapewizardpage.ui \
    sizes.ui \
    rotationmax.ui \
    sizeswizardpage.ui
