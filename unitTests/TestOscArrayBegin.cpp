#include <osc/composer/OscMessageComposer.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/reader/types/OscArrayBegin.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>


namespace {
	// The fixture for testing class ByteBuffer.
	class TestOscArrayBegin : public ::testing::Test {
	protected:
		TestOscArrayBegin()
		{
			mBuf = ByteBuffer::allocate(1024);
		}

		virtual ~TestOscArrayBegin()
		{
			delete mBuf;
		}

		ByteBuffer* mBuf;
	};

	TEST_F(TestOscArrayBegin, isArrayBegin)
	{
		OscArrayBegin osc(mBuf, 0);
		EXPECT_TRUE(osc.isArrayBegin());
	}

	TEST_F(TestOscArrayBegin, isArrayEnd)
	{
		OscArrayBegin osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayEnd());
	}

	TEST_F(TestOscArrayBegin, isFalse)
	{
		OscArrayBegin osc(mBuf, 0);
		EXPECT_FALSE(osc.isFalse());
	}

	TEST_F(TestOscArrayBegin, isTrue)
	{
		OscArrayBegin osc(mBuf, 0);
		EXPECT_FALSE(osc.isTrue());
	}

	TEST_F(TestOscArrayBegin, isNil)
	{
		OscArrayBegin osc(mBuf, 0);
		EXPECT_FALSE(osc.isNil());
	}

	TEST_F(TestOscArrayBegin, isInfinitum)
	{
		OscArrayBegin osc(mBuf, 0);
		EXPECT_FALSE(osc.isInfinitum());
	}

	TEST_F(TestOscArrayBegin, toBoolean)
	{
		OscArrayBegin osc(mBuf, 0);
		EXPECT_TRUE(osc.toBoolean());
	}

	TEST_F(TestOscArrayBegin, toBytes)
	{
		OscArrayBegin osc(mBuf, 0);
		EXPECT_EQ(osc.toBytes(), QByteArray(1, 1));
	}

	TEST_F(TestOscArrayBegin, toChar)
	{
		OscArrayBegin osc(mBuf, 0);
		EXPECT_EQ(osc.toChar(), QChar('['));
	}

	TEST_F(TestOscArrayBegin, toFloat)
	{
		OscArrayBegin osc(mBuf, 0);
		EXPECT_FLOAT_EQ(osc.toFloat(), 1.0f);
	}

	TEST_F(TestOscArrayBegin, toDouble)
	{
		OscArrayBegin osc(mBuf, 0);
		EXPECT_DOUBLE_EQ(osc.toDouble(), 1.0);
	}

	TEST_F(TestOscArrayBegin, toInteger)
	{
		OscArrayBegin osc(mBuf, 0);
		EXPECT_EQ(osc.toInteger(), 1);
	}

	TEST_F(TestOscArrayBegin, toLong)
	{
		OscArrayBegin osc(mBuf, 0);
		EXPECT_EQ(osc.toLong(), 1);
	}

	TEST_F(TestOscArrayBegin, toMIDI)
	{
		OscArrayBegin osc(mBuf, 0);
		EXPECT_THROW(osc.toMIDI(), MidiConversionException);
	}

	TEST_F(TestOscArrayBegin, toRGBA)
	{
		OscArrayBegin osc(mBuf, 0);
		EXPECT_THROW(osc.toRGBA(), RgbaConversionException);
	}

	TEST_F(TestOscArrayBegin, toString)
	{
		OscArrayBegin osc(mBuf, 0);
		EXPECT_EQ(osc.toString(), QChar('['));
	}

	TEST_F(TestOscArrayBegin, toSymbol)
	{
		OscArrayBegin osc(mBuf, 0);
		EXPECT_EQ(osc.toSymbol(), QChar('['));
	}

	TEST_F(TestOscArrayBegin, toTimetag)
	{
		OscArrayBegin osc(mBuf, 0);
		EXPECT_THROW(osc.toTimetag(), TimetagConversionException);
	}

	TEST_F(TestOscArrayBegin, getTag)
	{
		OscArrayBegin osc(mBuf, 0);
		EXPECT_EQ(osc.getTag(), QChar('['));
	}

}
