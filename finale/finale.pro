QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ajout.cpp \
    connexion.cpp \
    employee.cpp \
    main.cpp \
    mainwindow.cpp \
    suppression.cpp

HEADERS += \
    ajout.h \
    connexion.h \
    employee.h \
    mainwindow.h \
    suppression.h

FORMS += \
    ajout.ui \
    connexion.ui \
    mainwindow.ui \
    suppression.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
