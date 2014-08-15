#include <osc/composer/OscMessageComposer.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/reader/types/OscNil.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>


namespace {
	// The fixture for testing class ByteBuffer.
	class TestOscNil : public ::testing::Test {
	protected:
		TestOscNil()
		{
			mBuf = ByteBuffer::allocate(1024);
		}

		virtual ~TestOscNil()
		{
			delete mBuf;
		}

		ByteBuffer* mBuf;
	};

	TEST_F(TestOscNil, isArrayBegin)
	{
		OscNil osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayBegin());
	}

	TEST_F(TestOscNil, isArrayEnd)
	{
		OscNil osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayEnd());
	}

	TEST_F(TestOscNil, isFalse)
	{
		OscNil osc(mBuf, 0);
		EXPECT_FALSE(osc.isFalse());
	}

	TEST_F(TestOscNil, isTrue)
	{
		OscNil osc(mBuf, 0);
		EXPECT_FALSE(osc.isTrue());
	}

	TEST_F(TestOscNil, isNil)
	{
		OscNil osc(mBuf, 0);
		EXPECT_TRUE(osc.isNil());
	}

	TEST_F(TestOscNil, isInfinitum)
	{
		OscNil osc(mBuf, 0);
		EXPECT_FALSE(osc.isInfinitum());
	}

	TEST_F(TestOscNil, toBoolean)
	{
		OscNil osc(mBuf, 0);
		EXPECT_FALSE(osc.toBoolean());
	}

	TEST_F(TestOscNil, toBytes)
	{
		OscNil osc(mBuf, 0);
		EXPECT_EQ(osc.toBytes(), QByteArray(1, 0));
	}

	TEST_F(TestOscNil, toChar)
	{
		OscNil osc(mBuf, 0);
		EXPECT_EQ(osc.toChar(), QChar('\0'));
	}

	TEST_F(TestOscNil, toFloat)
	{
		OscNil osc(mBuf, 0);
		EXPECT_FLOAT_EQ(osc.toFloat(), 0.0f);
	}

	TEST_F(TestOscNil, toDouble)
	{
		OscNil osc(mBuf, 0);
		EXPECT_DOUBLE_EQ(osc.toDouble(), 0.0);
	}

	TEST_F(TestOscNil, toInteger)
	{
		OscNil osc(mBuf, 0);
		EXPECT_EQ(osc.toInteger(), 0);
	}

	TEST_F(TestOscNil, toLong)
	{
		OscNil osc(mBuf, 0);
		EXPECT_EQ(osc.toLong(), 0);
	}

	TEST_F(TestOscNil, toMIDI)
	{
		OscNil osc(mBuf, 0);
		EXPECT_THROW(osc.toMIDI(), MidiConversionException);
	}

	TEST_F(TestOscNil, toRGBA)
	{
		OscNil osc(mBuf, 0);
		EXPECT_THROW(osc.toRGBA(), RgbaConversionException);
	}

	TEST_F(TestOscNil, toString)
	{
		OscNil osc(mBuf, 0);
		EXPECT_EQ(osc.toString(), QString("NIL"));
	}

	TEST_F(TestOscNil, toSymbol)
	{
		OscNil osc(mBuf, 0);
		EXPECT_EQ(osc.toSymbol(), QChar('N'));
	}

	TEST_F(TestOscNil, toTimetag)
	{
		OscNil osc(mBuf, 0);
		EXPECT_THROW(osc.toTimetag(), TimetagConversionException);
	}

	TEST_F(TestOscNil, getTag)
	{
		OscNil osc(mBuf, 0);
		EXPECT_EQ(osc.getTag(), 'N');
	}

}
