#-------------------------------------------------
#
# library of OpenCL implementation of GOST 28147-89 cryptographic algorithm
#
#-------------------------------------------------

QT       -= core gui

CONFIG += c++11

TARGET = libgostCL
TEMPLATE = lib

DEFINES += LIBGOSTCL_LIBRARY

SOURCES += libgostcl.cpp

HEADERS += libgostcl.h\
        libgostcl_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
