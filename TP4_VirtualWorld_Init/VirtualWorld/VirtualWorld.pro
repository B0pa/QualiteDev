# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = TP4_VirtualWorld
QT       += core gui opengl widgets
CONFIG += c++17
QMAKE_CFLAGS += -DENABLE_QT6=0

HEADERS = \
   controller.h \
   observer.h \
   shape.h \
   shapefactory.h \
   shapemanager.h \
   paintview.h \
   treeview.h \
   virtualworld.h

SOURCES = \
   controller.cpp \
   main.cpp \
   paintview.cpp \
   shape.cpp \
   shapefactory.cpp \
   shapemanager.cpp \
   treeview.cpp \
   virtualworld.cpp

FORMS += \
    virtualworld.ui

RESOURCES += \
    virtualworld.qrc

#DEFINES = 

