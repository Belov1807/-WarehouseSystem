QT       += core gui sql

VERSION = 0.2.0

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

OBJECTS_DIR = .BUILD
MOC_DIR = .BUILD
UI_DIR = .BUILD
DESTDIR = .bin

CONFIG += c++11


DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
src/WarehouseSystemCustomer.cpp \
src/WarehouseSystemCustomersTableModel.cpp \
    src/WarehouseSystemCustomersWidget.cpp \
src/WarehouseSystemDataBaseManager.cpp \
src/WarehouseSystemDataManager.cpp \
    src/WarehouseSystemInfoOfCompanyWidget.cpp \
src/main.cpp \
src/WarehouseSystemMainWindow.cpp



HEADERS += \
src/WarehouseSystemCustomer.h \
src/WarehouseSystemCustomersTableModel.h \
    src/WarehouseSystemCustomersWidget.h \
src/WarehouseSystemDataBaseManager.h \
src/WarehouseSystemDataManager.h \
    src/WarehouseSystemInfoOfCompanyWidget.h \
src/WarehouseSystemMainWindow.h


FORMS += \
    src/WarehouseSystemCustomersWidget.ui \
    src/WarehouseSystemInfoOfCompanyWidget.ui \
src/WarehouseSystemMainWindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
