#include <osc/composer/OscMessageComposer.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/reader/types/OscFalse.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>


namespace {
	// The fixture for testing class ByteBuffer.
	class TestOscFalse : public ::testing::Test {
	protected:
		TestOscFalse()
		{
			mBuf = ByteBuffer::allocate(1024);
		}

		virtual ~TestOscFalse()
		{
			delete mBuf;
		}

		ByteBuffer* mBuf;
	};

	TEST_F(TestOscFalse, isArrayBegin)
	{
		OscFalse osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayBegin());
	}

	TEST_F(TestOscFalse, isArrayEnd)
	{
		OscFalse osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayEnd());
	}

	TEST_F(TestOscFalse, isFalse)
	{
		OscFalse osc(mBuf, 0);
		EXPECT_TRUE(osc.isFalse());
	}

	TEST_F(TestOscFalse, isTrue)
	{
		OscFalse osc(mBuf, 0);
		EXPECT_FALSE(osc.isTrue());
	}

	TEST_F(TestOscFalse, isNil)
	{
		OscFalse osc(mBuf, 0);
		EXPECT_FALSE(osc.isNil());
	}

	TEST_F(TestOscFalse, isInfinitum)
	{
		OscFalse osc(mBuf, 0);
		EXPECT_FALSE(osc.isInfinitum());
	}

	TEST_F(TestOscFalse, toBoolean)
	{
		OscFalse osc(mBuf, 0);
		EXPECT_FALSE(osc.toBoolean());
	}

	TEST_F(TestOscFalse, toBytes)
	{
		OscFalse osc(mBuf, 0);
		EXPECT_EQ(osc.toBytes(), QByteArray(1, 0));
	}

	TEST_F(TestOscFalse, toChar)
	{
		OscFalse osc(mBuf, 0);
		EXPECT_EQ(osc.toChar(), QChar('F'));
	}

	TEST_F(TestOscFalse, toFloat)
	{
		OscFalse osc(mBuf, 0);
		EXPECT_FLOAT_EQ(osc.toFloat(), 0.0f);
	}

	TEST_F(TestOscFalse, toDouble)
	{
		OscFalse osc(mBuf, 0);
		EXPECT_DOUBLE_EQ(osc.toDouble(), 0.0);
	}

	TEST_F(TestOscFalse, toInteger)
	{
		OscFalse osc(mBuf, 0);
		EXPECT_EQ(osc.toInteger(), 0);
	}

	TEST_F(TestOscFalse, toLong)
	{
		OscFalse osc(mBuf, 0);
		EXPECT_EQ(osc.toLong(), 0);
	}

	TEST_F(TestOscFalse, toMIDI)
	{
		OscFalse osc(mBuf, 0);
		EXPECT_THROW(osc.toMIDI(), MidiConversionException);
	}

	TEST_F(TestOscFalse, toRGBA)
	{
		OscFalse osc(mBuf, 0);
		EXPECT_THROW(osc.toRGBA(), RgbaConversionException);
	}

	TEST_F(TestOscFalse, toString)
	{
		OscFalse osc(mBuf, 0);
		EXPECT_EQ(osc.toString(), QString("FALSE"));
	}

	TEST_F(TestOscFalse, toSymbol)
	{
		OscFalse osc(mBuf, 0);
		EXPECT_EQ(osc.toSymbol(), QChar('F'));
	}

	TEST_F(TestOscFalse, toTimetag)
	{
		OscFalse osc(mBuf, 0);
		EXPECT_THROW(osc.toTimetag(), TimetagConversionException);
	}

	TEST_F(TestOscFalse, getTag)
	{
		OscFalse osc(mBuf, 0);
		EXPECT_EQ(osc.getTag(), 'F');
	}

}
