QT += qml quick widgets

CONFIG += c++11

SOURCES += src/main.cpp \
    src/ImageRenderItem.cpp

RESOURCES += ./qml/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    src/ImageRenderItem.h
