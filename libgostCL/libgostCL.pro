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

DESTDIR = ../output

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
    libgostcl_c.h \
    crypt_types.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    gostdecrypt.cl

unix|win32: LIBS += -lOpenCL


