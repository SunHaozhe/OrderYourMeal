#-------------------------------------------------
#
# Project created by QtCreator 2018-03-31T21:39:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OrderYourMeal
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    plat.cpp \
    filter.cpp \
	additionwindow.cpp

HEADERS  += widget.h \
    plat.h \
    filter.h \
    additionwindow.h

FORMS    += widget.ui \
    filter.ui \
	additionwindow.ui

RESOURCES += \
    r.qrc


