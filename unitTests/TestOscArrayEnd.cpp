#include <osc/composer/OscMessageComposer.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/reader/types/OscArrayEnd.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>


namespace {
	// The fixture for testing class ByteBuffer.
	class TestOscArrayEnd : public ::testing::Test {
	protected:
		TestOscArrayEnd()
		{
			mBuf = ByteBuffer::allocate(1024);
		}

		virtual ~TestOscArrayEnd()
		{
			delete mBuf;
		}

		ByteBuffer* mBuf;
	};

	TEST_F(TestOscArrayEnd, isArrayBegin)
	{
		OscArrayEnd osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayBegin());
	}

	TEST_F(TestOscArrayEnd, isArrayEnd)
	{
		OscArrayEnd osc(mBuf, 0);
		EXPECT_TRUE(osc.isArrayEnd());
	}

	TEST_F(TestOscArrayEnd, isFalse)
	{
		OscArrayEnd osc(mBuf, 0);
		EXPECT_FALSE(osc.isFalse());
	}

	TEST_F(TestOscArrayEnd, isTrue)
	{
		OscArrayEnd osc(mBuf, 0);
		EXPECT_FALSE(osc.isTrue());
	}

	TEST_F(TestOscArrayEnd, isNil)
	{
		OscArrayEnd osc(mBuf, 0);
		EXPECT_FALSE(osc.isNil());
	}

	TEST_F(TestOscArrayEnd, isInfinitum)
	{
		OscArrayEnd osc(mBuf, 0);
		EXPECT_FALSE(osc.isInfinitum());
	}

	TEST_F(TestOscArrayEnd, toBoolean)
	{
		OscArrayEnd osc(mBuf, 0);
		EXPECT_FALSE(osc.toBoolean());
	}

	TEST_F(TestOscArrayEnd, toBytes)
	{
		OscArrayEnd osc(mBuf, 0);
		EXPECT_EQ(osc.toBytes(), QByteArray(1, 0));
	}

	TEST_F(TestOscArrayEnd, toChar)
	{
		OscArrayEnd osc(mBuf, 0);
		EXPECT_EQ(osc.toChar(), QChar(']'));
	}

	TEST_F(TestOscArrayEnd, toFloat)
	{
		OscArrayEnd osc(mBuf, 0);
		EXPECT_FLOAT_EQ(osc.toFloat(), 0.0f);
	}

	TEST_F(TestOscArrayEnd, toDouble)
	{
		OscArrayEnd osc(mBuf, 0);
		EXPECT_DOUBLE_EQ(osc.toDouble(), 0.0);
	}

	TEST_F(TestOscArrayEnd, toInteger)
	{
		OscArrayEnd osc(mBuf, 0);
		EXPECT_EQ(osc.toInteger(), 0);;
	}

	TEST_F(TestOscArrayEnd, toLong)
	{
		OscArrayEnd osc(mBuf, 0);
		EXPECT_EQ(osc.toLong(), 0);
	}

	TEST_F(TestOscArrayEnd, toMIDI)
	{
		OscArrayEnd osc(mBuf, 0);
		EXPECT_THROW(osc.toMIDI(), MidiConversionException);
	}

	TEST_F(TestOscArrayEnd, toRGBA)
	{
		OscArrayEnd osc(mBuf, 0);
		EXPECT_THROW(osc.toRGBA(), RgbaConversionException);
	}

	TEST_F(TestOscArrayEnd, toString)
	{
		OscArrayEnd osc(mBuf, 0);
		EXPECT_EQ(osc.toString(), QChar(']'));
	}

	TEST_F(TestOscArrayEnd, toSymbol)
	{
		OscArrayEnd osc(mBuf, 0);
		EXPECT_EQ(osc.toSymbol(), QChar(']'));
	}

	TEST_F(TestOscArrayEnd, toTimetag)
	{
		OscArrayEnd osc(mBuf, 0);
		EXPECT_THROW(osc.toTimetag(), TimetagConversionException);
	}

	TEST_F(TestOscArrayEnd, getTag)
	{
		OscArrayEnd osc(mBuf, 0);
		EXPECT_EQ(osc.getTag(), QChar(']'));
	}

}
