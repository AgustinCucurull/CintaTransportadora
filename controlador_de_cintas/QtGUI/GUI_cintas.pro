QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -Wa,-mbig-obj

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addbelt.cpp \
    addcontroller.cpp \
    addsensor.cpp \
    conexion.cpp \
    data.cpp \
    interprete.cpp \
    main.cpp \
    mainwindow.cpp \
    port.cpp \
    queue.cpp

HEADERS += \
    addbelt.h \
    addcontroller.h \
    addsensor.h \
    conexion.h \
    data.h \
    interprete.h \
    mainwindow.h \
    port.h \
    queue.h \
    system_manager.h

FORMS += \
    addbelt.ui \
    addcontroller.ui \
    addsensor.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagenes.qrc
