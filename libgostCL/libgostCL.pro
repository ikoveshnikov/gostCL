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

SOURCES += libgostcl.cpp \
    errormessages.cpp \
    crypter.cpp \
    settingsholder.cpp \
    libgostcl_c.cpp

HEADERS += libgostcl.h\
        libgostcl_global.h \
    errormessages.h \
    crypter.h \
    settingsholder.h \
    libgostcl_c.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
