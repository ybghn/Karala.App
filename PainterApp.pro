QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
QT += opengl
LIBS += -lopengl32
SOURCES += \
    Shapes/box.cpp \
    Shapes/circle.cpp \
    Shapes/point.cpp \
    Shapes/shape.cpp \
    Shapes/triangle.cpp \
    canvas.cpp \
    Shapes/line.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Shapes/box.h \
    Shapes/circle.h \
    Shapes/point.h \
    Shapes/shape.h \
    Shapes/triangle.h \
    canvas.h \
    Shapes/line.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Shader/DefaultFragmentShader.frag \
    Shader/DefaultVertexShader.vert
