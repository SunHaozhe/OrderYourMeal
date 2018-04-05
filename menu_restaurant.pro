#-------------------------------------------------
#
# Project created by QtCreator 2016-03-02T09:11:52
#
#-------------------------------------------------


QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = menu_restaurant
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    plat.cpp \
    menu.cpp \
    boisson.cpp \
    clientedit.cpp \
    clientinput.cpp \
    dislike.cpp \
    emenu.cpp \
    food_list.cpp \
    homepage.cpp \
    introwindow.cpp \
    like.cpp \
    panier.cpp \
    panierwindow.cpp \
    platintro.cpp \
    form.cpp

HEADERS  += mainwindow.h \
    plat.h \
    menu.h \
    boisson.h \
    clientedit.h \
    clientinput.h \
    dislike.h \
    emenu.h \
    food_list.h \
    homepage.h \
    introwindow.h \
    like.h \
    panier.h \
    panierwindow.h \
    platintro.h \
    form.h

FORMS    += mainwindow.ui \
    clientinput.ui \
    homepage.ui \
    panierwindow.ui \
    mainwindow.ui \
    form.ui

DISTFILES += \
    menu.xml

RESOURCES += \
    xmlsources.qrc
