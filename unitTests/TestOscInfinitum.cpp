#include <osc/composer/OscMessageComposer.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/reader/types/OscInfinitum.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>


namespace {
	// The fixture for testing class ByteBuffer.
	class TestOscInfinitum : public ::testing::Test {
	protected:
		TestOscInfinitum()
		{
			mBuf = ByteBuffer::allocate(1024);
		}

		virtual ~TestOscInfinitum()
		{
			delete mBuf;
		}

		ByteBuffer* mBuf;
	};

	TEST_F(TestOscInfinitum, isArrayBegin)
	{
		OscInfinitum osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayBegin());
	}

	TEST_F(TestOscInfinitum, isArrayEnd)
	{
		OscInfinitum osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayEnd());
	}

	TEST_F(TestOscInfinitum, isFalse)
	{
		OscInfinitum osc(mBuf, 0);
		EXPECT_FALSE(osc.isFalse());
	}

	TEST_F(TestOscInfinitum, isTrue)
	{
		OscInfinitum osc(mBuf, 0);
		EXPECT_FALSE(osc.isTrue());
	}

	TEST_F(TestOscInfinitum, isNil)
	{
		OscInfinitum osc(mBuf, 0);
		EXPECT_FALSE(osc.isNil());
	}

	TEST_F(TestOscInfinitum, isInfinitum)
	{
		OscInfinitum osc(mBuf, 0);
		EXPECT_TRUE(osc.isInfinitum());
	}

	TEST_F(TestOscInfinitum, toBoolean)
	{
		OscInfinitum osc(mBuf, 0);
		EXPECT_TRUE(osc.toBoolean());
	}

	TEST_F(TestOscInfinitum, toBytes)
	{
		OscInfinitum osc(mBuf, 0);
		EXPECT_EQ(osc.toBytes(), QByteArray(1, std::numeric_limits<unsigned char>::infinity()));
	}

	TEST_F(TestOscInfinitum, toChar)
	{
		OscInfinitum osc(mBuf, 0);
		EXPECT_EQ(osc.toChar(), QChar(std::numeric_limits<char>::infinity()));
	}

	TEST_F(TestOscInfinitum, toFloat)
	{
		OscInfinitum osc(mBuf, 0);
		EXPECT_FLOAT_EQ(osc.toFloat(), std::numeric_limits<float>::infinity());
	}

	TEST_F(TestOscInfinitum, toDouble)
	{
		OscInfinitum osc(mBuf, 0);
		EXPECT_DOUBLE_EQ(osc.toDouble(), std::numeric_limits<double>::infinity());
	}

	TEST_F(TestOscInfinitum, toInteger)
	{
		OscInfinitum osc(mBuf, 0);
		EXPECT_EQ(osc.toInteger(), std::numeric_limits<qint32>::infinity());
	}

	TEST_F(TestOscInfinitum, toLong)
	{
		OscInfinitum osc(mBuf, 0);
		EXPECT_EQ(osc.toLong(), std::numeric_limits<qint64>::infinity());
	}

	TEST_F(TestOscInfinitum, toMIDI)
	{
		OscInfinitum osc(mBuf, 0);
		EXPECT_THROW(osc.toMIDI(), MidiConversionException);
	}

	TEST_F(TestOscInfinitum, toRGBA)
	{
		OscInfinitum osc(mBuf, 0);
		EXPECT_THROW(osc.toRGBA(), RgbaConversionException);
	}

	TEST_F(TestOscInfinitum, toString)
	{
		OscInfinitum osc(mBuf, 0);
		EXPECT_EQ(osc.toString(), QString("INF"));
	}

	TEST_F(TestOscInfinitum, toSymbol)
	{
		OscInfinitum osc(mBuf, 0);
		EXPECT_EQ(osc.toSymbol(), QChar('I'));
	}

	TEST_F(TestOscInfinitum, toTimetag)
	{
		OscInfinitum osc(mBuf, 0);
		EXPECT_THROW(osc.toTimetag(), TimetagConversionException);
	}

	TEST_F(TestOscInfinitum, getTag)
	{
		OscInfinitum osc(mBuf, 0);
		EXPECT_EQ(osc.getTag(), 'I');
	}

}
