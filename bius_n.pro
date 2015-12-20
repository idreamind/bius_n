#-------------------------------------------------
#
# Project created by QtCreator 2015-12-20T11:01:01
#
#-------------------------------------------------

QT       += core gui

CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bius_n
TEMPLATE = app


SOURCES += \
    main.cpp\
    TestView.cpp \
    src/NLabel.cpp \
    src/NPanel.cpp

HEADERS  += \
    TestView.h \
    Declarations.h \
    src/NLabel.h \
    src/NPanel.h

DEFINES += DEBUG_LEVEL=1
