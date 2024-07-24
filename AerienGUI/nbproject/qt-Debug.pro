# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = AerienGUI
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += AddArrival.cpp AddDeparture.cpp Airport_Table.cpp DeleteFlight.cpp main.cpp
HEADERS += AddArrival.h AddDeparture.h Airport_Table.h DeleteFlight.h
FORMS += AddArrival.ui AddDeparture.ui Airport_Table.ui DeleteFlight.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += ../Sources 
LIBS += ../Sources/dist/Debug/GNU-Linux/libsources.a  
