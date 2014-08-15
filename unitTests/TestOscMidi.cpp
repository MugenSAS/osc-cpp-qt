#include <osc/composer/OscMessageComposer.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/reader/types/OscMidi.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>


namespace {
	// The fixture for testing class ByteBuffer.
	class TestOscMidi : public ::testing::Test {
	protected:
		TestOscMidi()
		{
			mBuf = ByteBuffer::allocate(1024);
			mBuf->putChar(0x22);
			mBuf->putChar(0x11);
			mBuf->putChar(0x55);
			mBuf->putChar(0x66);
		}

		virtual ~TestOscMidi()
		{
			delete mBuf;
		}

		ByteBuffer* mBuf;
	};

	TEST_F(TestOscMidi, isArrayBegin)
	{
		OscMidi osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayBegin());
	}

	TEST_F(TestOscMidi, isArrayEnd)
	{
		OscMidi osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayEnd());
	}

	TEST_F(TestOscMidi, isFalse)
	{
		OscMidi osc(mBuf, 0);
		EXPECT_FALSE(osc.isFalse());
	}

	TEST_F(TestOscMidi, isTrue)
	{
		OscMidi osc(mBuf, 0);
		EXPECT_FALSE(osc.isTrue());
	}

	TEST_F(TestOscMidi, isNil)
	{
		OscMidi osc(mBuf, 0);
		EXPECT_FALSE(osc.isNil());
	}

	TEST_F(TestOscMidi, isInfinitum)
	{
		OscMidi osc(mBuf, 0);
		EXPECT_FALSE(osc.isInfinitum());
	}

	TEST_F(TestOscMidi, toBoolean)
	{
		OscMidi osc(mBuf, 0);
		EXPECT_TRUE(osc.toBoolean());
	}

	TEST_F(TestOscMidi, toBytes)
	{
		OscMidi osc(mBuf, 0);
		QByteArray bytes(4, 0);
		bytes[0] = 0x22;
		bytes[1] = 0x11;
		bytes[2] = 0x55;
		bytes[3] = 0x66;
		EXPECT_EQ(osc.toBytes(), bytes);
	}

	TEST_F(TestOscMidi, toChar)
	{
		OscMidi osc(mBuf, 0);
		EXPECT_THROW(osc.toChar(), CharConversionException);
	}

	TEST_F(TestOscMidi, toFloat)
	{
		OscMidi osc(mBuf, 0);
		EXPECT_THROW(osc.toFloat(), FloatConversionException);
	}

	TEST_F(TestOscMidi, toDouble)
	{
		OscMidi osc(mBuf, 0);
		EXPECT_THROW(osc.toDouble(), DoubleConversionException);
	}

	TEST_F(TestOscMidi, toInteger)
	{
		OscMidi osc(mBuf, 0);
		EXPECT_EQ(osc.toInteger(), 0x22115566);
	}

	TEST_F(TestOscMidi, toLong)
	{
		OscMidi osc(mBuf, 0);
		EXPECT_EQ(osc.toLong(), 0x22115566);
	}

	TEST_F(TestOscMidi, toMIDI)
	{
		OscMidi osc(mBuf, 0);
		EXPECT_EQ(osc.toMIDI(), Midi(0x22, 0x11, 0x55, 0x66));
	}

	TEST_F(TestOscMidi, toRGBA)
	{
		OscMidi osc(mBuf, 0);
		QByteArray bytes(4, 0);
		bytes[0] = 0x22;
		bytes[1] = 0x11;
		bytes[2] = 0x55;
		bytes[3] = 0x66;
		EXPECT_EQ(osc.toRGBA(), RGBA(bytes));
	}

	TEST_F(TestOscMidi, toString)
	{
		OscMidi osc(mBuf, 0);
		EXPECT_EQ(osc.toString(), QString::number(0x22115566, 16));
	}

	TEST_F(TestOscMidi, toSymbol)
	{
		OscMidi osc(mBuf, 0);
		EXPECT_EQ(osc.toSymbol(), QChar('m'));
	}

	TEST_F(TestOscMidi, toTimetag)
	{
		OscMidi osc(mBuf, 0);
		EXPECT_THROW(osc.toTimetag(), TimetagConversionException);
	}

	TEST_F(TestOscMidi, getTag)
	{
		OscMidi osc(mBuf, 0);
		EXPECT_EQ(osc.getTag(), 'm');
	}

}
