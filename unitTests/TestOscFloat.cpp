#include <osc/composer/OscMessageComposer.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/reader/types/OscFloat.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>


namespace {
	// The fixture for testing class ByteBuffer.
	class TestOscFloat : public ::testing::Test {
	protected:
		TestOscFloat()
			: mValue(1568.23564f)
		{
			mBuf = ByteBuffer::allocate(1024);
			mBuf->putFloat(mValue);
		}

		virtual ~TestOscFloat()
		{
			delete mBuf;
		}

		ByteBuffer* mBuf;
		float mValue;
	};

	TEST_F(TestOscFloat, isArrayBegin)
	{
		OscFloat osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayBegin());
	}

	TEST_F(TestOscFloat, isArrayEnd)
	{
		OscFloat osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayEnd());
	}

	TEST_F(TestOscFloat, isFalse)
	{
		OscFloat osc(mBuf, 0);
		EXPECT_FALSE(osc.isFalse());
	}

	TEST_F(TestOscFloat, isTrue)
	{
		OscFloat osc(mBuf, 0);
		EXPECT_FALSE(osc.isTrue());
	}

	TEST_F(TestOscFloat, isNil)
	{
		OscFloat osc(mBuf, 0);
		EXPECT_FALSE(osc.isNil());
	}

	TEST_F(TestOscFloat, isInfinitum)
	{
		OscFloat osc(mBuf, 0);
		EXPECT_FALSE(osc.isInfinitum());
	}

	TEST_F(TestOscFloat, toBoolean)
	{
		OscFloat osc(mBuf, 0);
		EXPECT_TRUE(osc.toBoolean());
	}

	TEST_F(TestOscFloat, toBytes)
	{
		OscFloat osc(mBuf, 0);
		QByteArray bytes(4, 0);
		bytes.insert(0, (char*)&mValue, 4);
		EXPECT_EQ(osc.toBytes(), bytes);
	}

	TEST_F(TestOscFloat, toChar)
	{
		OscFloat osc(mBuf, 0);
		EXPECT_THROW(osc.toChar(), CharConversionException);
	}

	TEST_F(TestOscFloat, toFloat)
	{
		OscFloat osc(mBuf, 0);
		EXPECT_FLOAT_EQ(osc.toFloat(), float(mValue));
	}

	TEST_F(TestOscFloat, toDouble)
	{
		OscFloat osc(mBuf, 0);
		EXPECT_DOUBLE_EQ(osc.toDouble(), double(mValue));
	}

	TEST_F(TestOscFloat, toInteger)
	{
		OscFloat osc(mBuf, 0);
		EXPECT_EQ(osc.toInteger(), (qint32)mValue);
	}

	TEST_F(TestOscFloat, toLong)
	{
		OscFloat osc(mBuf, 0);
		EXPECT_EQ(osc.toLong(), (qint64)mValue);
	}

	TEST_F(TestOscFloat, toMIDI)
	{
		OscFloat osc(mBuf, 0);
		QByteArray bytes(4, 0);
		bytes.insert(0, (char*)&mValue, 4);
		EXPECT_EQ(osc.toMIDI(), Midi(bytes));
	}

	TEST_F(TestOscFloat, toRGBA)
	{
		OscFloat osc(mBuf, 0);
		QByteArray bytes(4, 0);
		bytes.insert(0, (char*)&mValue, 4);
		EXPECT_EQ(osc.toRGBA(), RGBA(bytes));
	}

	TEST_F(TestOscFloat, toString)
	{
		OscFloat osc(mBuf, 0);
		EXPECT_EQ(osc.toString(), QString::number(mValue));
	}

	TEST_F(TestOscFloat, toSymbol)
	{
		OscFloat osc(mBuf, 0);
		EXPECT_EQ(osc.toSymbol(), QChar('f'));
	}

	TEST_F(TestOscFloat, toTimetag)
	{
		OscFloat osc(mBuf, 0);
		EXPECT_THROW(osc.toTimetag(), TimetagConversionException);
	}

	TEST_F(TestOscFloat, getTag)
	{
		OscFloat osc(mBuf, 0);
		EXPECT_EQ(osc.getTag(), 'f');
	}

}
