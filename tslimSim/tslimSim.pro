QT       += core gui
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alertevent.cpp \
    boluscalculator.cpp \
    cgm.cpp \
    cgmevent.cpp \
    glucosereader_mock.cpp \
    event.cpp \
    eventhistory.cpp \
    insulindeliveryevent.cpp \
    insulindeliveryprofile.cpp \
    main.cpp \
    mainwindow.cpp \
    profile.cpp \
    profileformwidget.cpp \
    profilespagewidget.cpp

HEADERS += \
    alertevent.h \
    boluscalculator.h \
    cgm.h \
    cgmevent.h \
    glucosereader_mock.h \
    event.h \
    eventhistory.h \
    insulindeliveryevent.h \
    insulindeliveryprofile.h \
    mainwindow.h \
    profile.h \
    profileformwidget.h \
    profilespagewidget.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
