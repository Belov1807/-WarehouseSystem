QT       += core gui sql

VERSION = 0.5.0

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

OBJECTS_DIR = .BUILD
MOC_DIR = .BUILD
UI_DIR = .BUILD
DESTDIR = .bin

CONFIG += c++11


DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    src/WarehouseSystemArrangeOrderWidget.cpp \
src/WarehouseSystemCustomer.cpp \
src/WarehouseSystemCustomersTableModel.cpp \
src/WarehouseSystemCustomersWidget.cpp \
src/WarehouseSystemDataBaseManager.cpp \
src/WarehouseSystemDataManager.cpp \
src/WarehouseSystemInfoOfCompanyWidget.cpp \
    src/WarehouseSystemOrder.cpp \
    src/WarehouseSystemOrderOnePosition.cpp \
src/WarehouseSystemProduct.cpp \
src/WarehouseSystemProductTableModel.cpp \
src/WarehouseSystemProductWidget.cpp \
src/main.cpp \
src/WarehouseSystemMainWindow.cpp

HEADERS += \
    src/WarehouseSystemArrangeOrderWidget.h \
src/WarehouseSystemCustomer.h \
src/WarehouseSystemCustomersTableModel.h \
src/WarehouseSystemCustomersWidget.h \
src/WarehouseSystemDataBaseManager.h \
src/WarehouseSystemDataManager.h \
src/WarehouseSystemInfoOfCompanyWidget.h \
src/WarehouseSystemMainWindow.h \
    src/WarehouseSystemOrder.h \
    src/WarehouseSystemOrderOnePosition.h \
src/WarehouseSystemProduct.h \
src/WarehouseSystemProductTableModel.h \
src/WarehouseSystemProductWidget.h

FORMS += \
    src/WarehouseSystemArrangeOrderWidget.ui \
src/WarehouseSystemCustomersWidget.ui \
src/WarehouseSystemInfoOfCompanyWidget.ui \
src/WarehouseSystemMainWindow.ui \
src/WarehouseSystemProductWidget.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
