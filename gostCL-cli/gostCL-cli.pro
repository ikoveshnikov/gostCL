#-------------------------------------------------
#
# Command line interface for libgostCL
#
#-------------------------------------------------

QT       -= core gui

CONFIG += c++11

TARGET = gostCL-cli
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

DESTDIR = ../output

SOURCES += main.cpp \
    gostclcrypter.cpp

HEADERS += \
    gostclcrypter.h
