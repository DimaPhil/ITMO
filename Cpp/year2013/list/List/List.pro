#-------------------------------------------------
#
# Project created by QtCreator 2015-06-13T14:06:51
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = List
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    iterator.cpp \
    const_iterator.cpp \
    node.cpp \
    list.cpp

HEADERS += \
    node.h \
    list.h \
    iterator.h \
    const_iterator.h
