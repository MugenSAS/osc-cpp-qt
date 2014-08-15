#include <osc/composer/OscMessageComposer.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/reader/types/OscChar.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>


namespace {
	// The fixture for testing class ByteBuffer.
	class TestOscChar : public ::testing::Test {
	protected:
		TestOscChar()
		{
			mBuf = ByteBuffer::allocate(1024);
			mBuf->putInt('#');
		}

		virtual ~TestOscChar()
		{
			delete mBuf;
		}

		ByteBuffer* mBuf;
	};

	TEST_F(TestOscChar, isArrayBegin)
	{
		OscChar osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayBegin());
	}

	TEST_F(TestOscChar, isArrayEnd)
	{
		OscChar osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayEnd());
	}

	TEST_F(TestOscChar, isFalse)
	{
		OscChar osc(mBuf, 0);
		EXPECT_FALSE(osc.isFalse());
	}

	TEST_F(TestOscChar, isTrue)
	{
		OscChar osc(mBuf, 0);
		EXPECT_FALSE(osc.isTrue());
	}

	TEST_F(TestOscChar, isNil)
	{
		OscChar osc(mBuf, 0);
		EXPECT_FALSE(osc.isNil());
	}

	TEST_F(TestOscChar, isInfinitum)
	{
		OscChar osc(mBuf, 0);
		EXPECT_FALSE(osc.isInfinitum());
	}

	TEST_F(TestOscChar, toBoolean)
	{
		OscChar osc(mBuf, 0);
		EXPECT_TRUE(osc.toBoolean());
	}

	TEST_F(TestOscChar, toBytes)
	{
		OscChar osc(mBuf, 0);
		EXPECT_EQ(osc.toBytes(), QByteArray(1, '#'));
	}

	TEST_F(TestOscChar, toChar)
	{
		OscChar osc(mBuf, 0);
		EXPECT_EQ(osc.toChar(), '#');
	}

	TEST_F(TestOscChar, toFloat)
	{
		OscChar osc(mBuf, 0);
		EXPECT_FLOAT_EQ(osc.toFloat(), '#');
	}

	TEST_F(TestOscChar, toDouble)
	{
		OscChar osc(mBuf, 0);
		EXPECT_DOUBLE_EQ(osc.toDouble(), '#');
	}

	TEST_F(TestOscChar, toInteger)
	{
		OscChar osc(mBuf, 0);
		EXPECT_EQ(osc.toInteger(), '#');
	}

	TEST_F(TestOscChar, toLong)
	{
		OscChar osc(mBuf, 0);
		EXPECT_EQ(osc.toLong(), '#');
	}

	TEST_F(TestOscChar, toMIDI)
	{
		OscChar osc(mBuf, 0);
		EXPECT_THROW(osc.toMIDI(), MidiConversionException);
	}

	TEST_F(TestOscChar, toRGBA)
	{
		OscChar osc(mBuf, 0);
		EXPECT_THROW(osc.toRGBA(), RgbaConversionException);
	}

	TEST_F(TestOscChar, toString)
	{
		OscChar osc(mBuf, 0);
		EXPECT_EQ(osc.toString(), QChar('#'));
	}

	TEST_F(TestOscChar, toSymbol)
	{
		OscChar osc(mBuf, 0);
		EXPECT_EQ(osc.toSymbol(), QChar('c'));
	}

	TEST_F(TestOscChar, toTimetag)
	{
		OscChar osc(mBuf, 0);
		EXPECT_THROW(osc.toTimetag(), TimetagConversionException);
	}

	TEST_F(TestOscChar, getTag)
	{
		OscChar osc(mBuf, 0);
		EXPECT_EQ(osc.getTag(), 'c');
	}

}
