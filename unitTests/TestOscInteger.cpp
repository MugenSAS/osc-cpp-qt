#include <osc/composer/OscMessageComposer.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/reader/types/OscInteger.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>


namespace {
	// The fixture for testing class ByteBuffer.
	class TestOscInteger : public ::testing::Test {
	protected:
		TestOscInteger()
			: mValue(0x88112233)
		{
			mBuf = ByteBuffer::allocate(1024);
			mBuf->putInt(mValue);
		}

		virtual ~TestOscInteger()
		{
			delete mBuf;
		}

		ByteBuffer* mBuf;
		qint32 mValue;
	};

	TEST_F(TestOscInteger, isArrayBegin)
	{
		OscInteger osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayBegin());
	}

	TEST_F(TestOscInteger, isArrayEnd)
	{
		OscInteger osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayEnd());
	}

	TEST_F(TestOscInteger, isFalse)
	{
		OscInteger osc(mBuf, 0);
		EXPECT_FALSE(osc.isFalse());
	}

	TEST_F(TestOscInteger, isTrue)
	{
		OscInteger osc(mBuf, 0);
		EXPECT_FALSE(osc.isTrue());
	}

	TEST_F(TestOscInteger, isNil)
	{
		OscInteger osc(mBuf, 0);
		EXPECT_FALSE(osc.isNil());
	}

	TEST_F(TestOscInteger, isInfinitum)
	{
		OscInteger osc(mBuf, 0);
		EXPECT_FALSE(osc.isInfinitum());
	}

	TEST_F(TestOscInteger, toBoolean)
	{
		OscInteger osc(mBuf, 0);
		EXPECT_TRUE(osc.toBoolean());
	}

	TEST_F(TestOscInteger, toBytes)
	{
		OscInteger osc(mBuf, 0);

		QByteArray bytes(4, 0);
		bytes.insert(0, (char*)&mValue, 4);
		EXPECT_EQ(osc.toBytes(), bytes);
	}

	TEST_F(TestOscInteger, toChar)
	{
		OscInteger osc(mBuf, 0);
		EXPECT_THROW(osc.toChar(), CharConversionException);
	}

	TEST_F(TestOscInteger, toFloat)
	{
		OscInteger osc(mBuf, 0);
		EXPECT_FLOAT_EQ(osc.toFloat(), (float)mValue);
	}

	TEST_F(TestOscInteger, toDouble)
	{
		OscInteger osc(mBuf, 0);
		EXPECT_DOUBLE_EQ(osc.toDouble(), (double)mValue);
	}

	TEST_F(TestOscInteger, toInteger)
	{
		OscInteger osc(mBuf, 0);
		EXPECT_EQ(osc.toInteger(), mValue);
	}

	TEST_F(TestOscInteger, toLong)
	{
		OscInteger osc(mBuf, 0);
		EXPECT_EQ(osc.toLong(), mValue);
	}

	TEST_F(TestOscInteger, toMIDI)
	{
		OscInteger osc(mBuf, 0);
		QByteArray bytes(4, 0);
		bytes.insert(0, (char*)&mValue, 4);
		EXPECT_EQ(osc.toMIDI(), Midi(bytes));
	}

	TEST_F(TestOscInteger, toRGBA)
	{
		OscInteger osc(mBuf, 0);
		QByteArray bytes(4, 0);
		bytes.insert(0, (char*)&mValue, 4);
		EXPECT_EQ(osc.toRGBA(), RGBA(bytes));
	}

	TEST_F(TestOscInteger, toString)
	{
		OscInteger osc(mBuf, 0);
		EXPECT_EQ(osc.toString(), QString::number(mValue));
	}

	TEST_F(TestOscInteger, toSymbol)
	{
		OscInteger osc(mBuf, 0);
		EXPECT_EQ(osc.toSymbol(), QChar('i'));
	}

	TEST_F(TestOscInteger, toTimetag)
	{
		OscInteger osc(mBuf, 0);
		EXPECT_THROW(osc.toTimetag(), TimetagConversionException);
	}

	TEST_F(TestOscInteger, getTag)
	{
		OscInteger osc(mBuf, 0);
		EXPECT_EQ(osc.getTag(), 'i');
	}

}
