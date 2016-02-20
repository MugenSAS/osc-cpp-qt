QT       -= gui

TARGET = osc
TEMPLATE = lib

DEFINES += OSC_EXPORT

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

HEADERS += \
    osc/composer/OscBundleComposer.h \
    osc/composer/OscContentComposer.h \
    osc/composer/OscMessageComposer.h \
    osc/exceptions/BooleanConversionException.h \
    osc/exceptions/BytesConversionException.h \
    osc/exceptions/CharConversionException.h \
    osc/exceptions/DoubleConversionException.h \
    osc/exceptions/FloatConversionException.h \
    osc/exceptions/GetBundleException.h \
    osc/exceptions/GetMessageException.h \
    osc/exceptions/IntegerConversionException.h \
    osc/exceptions/LongConversionException.h \
    osc/exceptions/MalformedArrayException.h \
    osc/exceptions/MalformedBundleException.h \
    osc/exceptions/MidiConversionException.h \
    osc/exceptions/OSC_ALL_EXCEPTIONS.h \
    osc/exceptions/OutOfBoundsReadException.h \
    osc/exceptions/ReadMessageException.h \
    osc/exceptions/RgbaConversionException.h \
    osc/exceptions/StringConversionException.h \
    osc/exceptions/SymbolConversionException.h \
    osc/exceptions/TimetagConversionException.h \
    osc/exceptions/UnknownTagException.h \
    osc/OscAPI.h \
    osc/OscPatternMatching.h \
    osc/OscVersion.h \
    osc/reader/OscBundle.h \
    osc/reader/OscContent.h \
    osc/reader/OscMessage.h \
    osc/reader/OscReader.h \
    osc/reader/types/Midi.h \
    osc/reader/types/OscAddress.h \
    osc/reader/types/OscArrayBegin.h \
    osc/reader/types/OscArrayEnd.h \
    osc/reader/types/OscBlob.h \
    osc/reader/types/OscChar.h \
    osc/reader/types/OscDouble.h \
    osc/reader/types/OscFalse.h \
    osc/reader/types/OscFloat.h \
    osc/reader/types/OscInfinitum.h \
    osc/reader/types/OscInteger.h \
    osc/reader/types/OscLong.h \
    osc/reader/types/OscMidi.h \
    osc/reader/types/OscNil.h \
    osc/reader/types/OscRGBA.h \
    osc/reader/types/OscString.h \
    osc/reader/types/OscSymbol.h \
    osc/reader/types/OscTags.h \
    osc/reader/types/OscTimetag.h \
    osc/reader/types/OscTrue.h \
    osc/reader/types/OscValue.h \
    osc/reader/types/RGBA.h \
    osc/reader/types/Symbol.h \
    tools/ByteBuffer.h \
    tools/ByteOrder.h \
    tools/exceptions/BufferOverflowException.h \
    tools/exceptions/BufferUnderflowException.h \
    tools/exceptions/IllegalArgumentException.h \
    tools/exceptions/IndexOutOfBoundsException.h \
    tools/NtpTimestamp.h

SOURCES += \
    osc/composer/OscBundleComposer.cpp \
    osc/composer/OscContentComposer.cpp \
    osc/composer/OscMessageComposer.cpp \
    osc/OscPatternMatching.cpp \
    osc/reader/OscBundle.cpp \
    osc/reader/OscContent.cpp \
    osc/reader/OscMessage.cpp \
    osc/reader/OscReader.cpp \
    osc/reader/OscValue.cpp \
    osc/reader/types/OscAddress.cpp \
    osc/reader/types/OscArrayBegin.cpp \
    osc/reader/types/OscArrayEnd.cpp \
    osc/reader/types/OscBlob.cpp \
    osc/reader/types/OscChar.cpp \
    osc/reader/types/OscDouble.cpp \
    osc/reader/types/OscFalse.cpp \
    osc/reader/types/OscFloat.cpp \
    osc/reader/types/OscInfinitum.cpp \
    osc/reader/types/OscInteger.cpp \
    osc/reader/types/OscLong.cpp \
    osc/reader/types/OscMidi.cpp \
    osc/reader/types/OscNil.cpp \
    osc/reader/types/OscRGBA.cpp \
    osc/reader/types/OscString.cpp \
    osc/reader/types/OscSymbol.cpp \
    osc/reader/types/OscTags.cpp \
    osc/reader/types/OscTimeTag.cpp \
    osc/reader/types/OscTrue.cpp \
    tools/ByteBuffer.cpp \
    tools/ByteOrder.cpp \
    tools/NtpTimestamp.cpp
