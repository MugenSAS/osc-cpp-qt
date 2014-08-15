QT       -= gui

TARGET = oscTest
TEMPLATE = app

DEFINES += BUILD_UNITTESTS

CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/bin/debug
}
CONFIG(release, debug|release) {
    DESTDIR = $$PWD/bin/release
}

OBJECTS_DIR = $$DESTDIR/tmp/obj/$$TARGET/.obj
MOC_DIR = $$DESTDIR/tmp/moc/$$TARGET/.moc
RCC_DIR = $$DESTDIR/tmp/qrc/$$TARGET/.qrc
UI_DIR = $$DESTDIR/tmp/ui/$$TARGET/.ui

INCLUDEPATH += $$PWD/gtest/include

LIBS += -L$$PWD/gtest/lib -lgtest -L$$DESTDIR -losc

SOURCES += \
    unitTests/main.cpp \
    unitTests/TestByteBuffer.cpp \
    unitTests/TestOscAddress.cpp \
    unitTests/TestOscArrayBegin.cpp \
    unitTests/TestOscArrayEnd.cpp \
    unitTests/TestOscBlob.cpp \
    unitTests/TestOscChar.cpp \
    unitTests/TestOscDouble.cpp \
    unitTests/TestOscFalse.cpp \
    unitTests/TestOscFloat.cpp \
    unitTests/TestOscInfinitum.cpp \
    unitTests/TestOscInteger.cpp \
    unitTests/TestOscLong.cpp \
    unitTests/TestOscMessageComposer.cpp \
    unitTests/TestOscMidi.cpp \
    unitTests/TestOscNil.cpp \
    unitTests/TestOscPatternMatching.cpp \
    unitTests/TestOscReader.cpp \
    unitTests/TestOscRGBA.cpp \
    unitTests/TestOscString.cpp \
    unitTests/TestOscSymbol.cpp \
    unitTests/TestOscTimetag.cpp \
    unitTests/TestOscTrue.cpp

