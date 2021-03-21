QT       += core gui
QT += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


LIBS += -lOpenGL32

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    canvasnew.cpp \
    main.cpp \
    mainwindow.cpp \
    geotransform.cpp \
    gcp_icp_collections.cpp \
    opengl.cpp \
    txtread.cpp

HEADERS += \
    canvasnew.h \
    mainwindow.h \
    geotransform.h \
    gcp_icp_collections.h \
    opengl.h \
    txtread.h

FORMS += \
    canvasnew.ui \
    mainwindow.ui \
    geotransform.ui \
    gcp_icp_collections.ui

TRANSLATIONS += \
    GeoEtrim_tr_TR.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../MovieTapeinsta/movietape.png \
    C:/Users/Yunus Emre/Desktop/NEİZLESEMİCON/movietapeiconlar/movie_mini.png

RESOURCES +=
