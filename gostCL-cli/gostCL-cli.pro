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

win32:CONFIG(release, debug|release): LIBS += -L$$DESTDIR/ -llibgostCL
else:win32:CONFIG(debug, debug|release): LIBS += -L$$DESTDIR/ -llibgostCL
else:unix: LIBS += -L$$DESTDIR/ -llibgostCL

INCLUDEPATH += $$PWD/../libgostCL
DEPENDPATH += $$PWD/../libgostCL
