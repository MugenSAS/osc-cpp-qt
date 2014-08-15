#include <osc/composer/OscMessageComposer.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/reader/types/OscRGBA.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>


namespace {
	// The fixture for testing class ByteBuffer.
	class TestOscRGBA : public ::testing::Test {
	protected:
		TestOscRGBA()
			: mValue(0x22115566)
		{
			mBuf = ByteBuffer::allocate(1024);
			mBuf->putInt(mValue);
		}

		virtual ~TestOscRGBA()
		{
			delete mBuf;
		}

		ByteBuffer* mBuf;
		qint32 mValue;
	};

	TEST_F(TestOscRGBA, isArrayBegin)
	{
		OscRGBA osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayBegin());
	}

	TEST_F(TestOscRGBA, isArrayEnd)
	{
		OscRGBA osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayEnd());
	}

	TEST_F(TestOscRGBA, isFalse)
	{
		OscRGBA osc(mBuf, 0);
		EXPECT_FALSE(osc.isFalse());
	}

	TEST_F(TestOscRGBA, isTrue)
	{
		OscRGBA osc(mBuf, 0);
		EXPECT_FALSE(osc.isTrue());
	}

	TEST_F(TestOscRGBA, isNil)
	{
		OscRGBA osc(mBuf, 0);
		EXPECT_FALSE(osc.isNil());
	}

	TEST_F(TestOscRGBA, isInfinitum)
	{
		OscRGBA osc(mBuf, 0);
		EXPECT_FALSE(osc.isInfinitum());
	}

	TEST_F(TestOscRGBA, toBoolean)
	{
		OscRGBA osc(mBuf, 0);
		EXPECT_TRUE(osc.toBoolean());
	}

	TEST_F(TestOscRGBA, toBytes)
	{
		OscRGBA osc(mBuf, 0);
		QByteArray bytes(4, 0);
		bytes.insert(0, (char*)&mValue, 4);
		EXPECT_EQ(osc.toBytes(), bytes);
	}

	TEST_F(TestOscRGBA, toChar)
	{
		OscRGBA osc(mBuf, 0);
		EXPECT_THROW(osc.toChar(), CharConversionException);
	}

	TEST_F(TestOscRGBA, toFloat)
	{
		OscRGBA osc(mBuf, 0);
		EXPECT_THROW(osc.toFloat(), FloatConversionException);
	}

	TEST_F(TestOscRGBA, toDouble)
	{
		OscRGBA osc(mBuf, 0);
		EXPECT_THROW(osc.toDouble(), DoubleConversionException);
	}

	TEST_F(TestOscRGBA, toInteger)
	{
		OscRGBA osc(mBuf, 0);
		EXPECT_EQ(osc.toInteger(), mValue);
	}

	TEST_F(TestOscRGBA, toLong)
	{
		OscRGBA osc(mBuf, 0);
		EXPECT_EQ(osc.toLong(), mValue);
	}

	TEST_F(TestOscRGBA, toMIDI)
	{
		OscRGBA osc(mBuf, 0);
		QByteArray bytes(4, 0);
		bytes.insert(0, (char*)&mValue, 4);
		EXPECT_EQ(osc.toMIDI(), Midi(bytes));
	}

	TEST_F(TestOscRGBA, toRGBA)
	{
		OscRGBA osc(mBuf, 0);
		QByteArray bytes(4, 0);
		bytes.insert(0, (char*)&mValue, 4);
		EXPECT_EQ(osc.toRGBA(), RGBA(bytes));
	}

	TEST_F(TestOscRGBA, toString)
	{
		OscRGBA osc(mBuf, 0);
		EXPECT_EQ(osc.toString(), QString::number(mValue, 16));
	}

	TEST_F(TestOscRGBA, toSymbol)
	{
		OscRGBA osc(mBuf, 0);
		EXPECT_EQ(osc.toSymbol(), QChar('r'));
	}

	TEST_F(TestOscRGBA, toTimetag)
	{
		OscRGBA osc(mBuf, 0);
		EXPECT_THROW(osc.toTimetag(), TimetagConversionException);
	}

	TEST_F(TestOscRGBA, getTag)
	{
		OscRGBA osc(mBuf, 0);
		EXPECT_EQ(osc.getTag(), 'r');
	}

}
