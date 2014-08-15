#include <osc/composer/OscMessageComposer.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/reader/types/OscTrue.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>


namespace {
	// The fixture for testing class ByteBuffer.
	class TestOscTrue : public ::testing::Test {
	protected:
		TestOscTrue()
		{
			mBuf = ByteBuffer::allocate(1024);
		}

		virtual ~TestOscTrue()
		{
			delete mBuf;
		}

		ByteBuffer* mBuf;
	};

	TEST_F(TestOscTrue, isArrayBegin)
	{
		OscTrue osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayBegin());
	}

	TEST_F(TestOscTrue, isArrayEnd)
	{
		OscTrue osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayEnd());
	}

	TEST_F(TestOscTrue, isFalse)
	{
		OscTrue osc(mBuf, 0);
		EXPECT_FALSE(osc.isFalse());
	}

	TEST_F(TestOscTrue, isTrue)
	{
		OscTrue osc(mBuf, 0);
		EXPECT_TRUE(osc.isTrue());
	}

	TEST_F(TestOscTrue, isNil)
	{
		OscTrue osc(mBuf, 0);
		EXPECT_FALSE(osc.isNil());
	}

	TEST_F(TestOscTrue, isInfinitum)
	{
		OscTrue osc(mBuf, 0);
		EXPECT_FALSE(osc.isInfinitum());
	}

	TEST_F(TestOscTrue, toBoolean)
	{
		OscTrue osc(mBuf, 0);
		EXPECT_TRUE(osc.toBoolean());
	}

	TEST_F(TestOscTrue, toBytes)
	{
		OscTrue osc(mBuf, 0);
		EXPECT_EQ(osc.toBytes(), QByteArray(1, 1));
	}

	TEST_F(TestOscTrue, toChar)
	{
		OscTrue osc(mBuf, 0);
		EXPECT_EQ(osc.toChar(), QChar('T'));
	}

	TEST_F(TestOscTrue, toFloat)
	{
		OscTrue osc(mBuf, 0);
		EXPECT_FLOAT_EQ(osc.toFloat(), 1.0f);
	}

	TEST_F(TestOscTrue, toDouble)
	{
		OscTrue osc(mBuf, 0);
		EXPECT_DOUBLE_EQ(osc.toDouble(), 1.0);
	}

	TEST_F(TestOscTrue, toInteger)
	{
		OscTrue osc(mBuf, 0);
		EXPECT_EQ(osc.toInteger(), 1);
	}

	TEST_F(TestOscTrue, toLong)
	{
		OscTrue osc(mBuf, 0);
		EXPECT_EQ(osc.toLong(), 1);
	}

	TEST_F(TestOscTrue, toMIDI)
	{
		OscTrue osc(mBuf, 0);
		EXPECT_THROW(osc.toMIDI(), MidiConversionException);
	}

	TEST_F(TestOscTrue, toRGBA)
	{
		OscTrue osc(mBuf, 0);
		EXPECT_THROW(osc.toRGBA(), RgbaConversionException);
	}

	TEST_F(TestOscTrue, toString)
	{
		OscTrue osc(mBuf, 0);
		EXPECT_EQ(osc.toString(), QString("TRUE"));
	}

	TEST_F(TestOscTrue, toSymbol)
	{
		OscTrue osc(mBuf, 0);
		EXPECT_EQ(osc.toSymbol(), QChar('T'));
	}

	TEST_F(TestOscTrue, toTimetag)
	{
		OscTrue osc(mBuf, 0);
		EXPECT_THROW(osc.toTimetag(), TimetagConversionException);
	}

	TEST_F(TestOscTrue, getTag)
	{
		OscTrue osc(mBuf, 0);
		EXPECT_EQ(osc.getTag(), 'T');
	}

}
