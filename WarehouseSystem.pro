QT       += core gui

VERSION = 0.1.0

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

OBJECTS_DIR = .BUILD
MOC_DIR = .BUILD
UI_DIR = .BUILD
DESTDIR = .bin

CONFIG += c++11


DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    src/WarehouseSystemInfoOfCompanyWidget.cpp \
src/main.cpp \
src/WarehouseSystemMainWindow.cpp



HEADERS += \
    src/WarehouseSystemInfoOfCompanyWidget.h \
src/WarehouseSystemMainWindow.h \


FORMS += \
    src/WarehouseSystemInfoOfCompanyWidget.ui \
src/WarehouseSystemMainWindow.ui \

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
