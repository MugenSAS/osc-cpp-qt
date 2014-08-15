#include <osc/composer/OscMessageComposer.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/reader/types/OscAddress.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>


namespace {
	// The fixture for testing class ByteBuffer.
	class TestOscAddress : public ::testing::Test {
	protected:
		TestOscAddress()
		{
			mBuf = ByteBuffer::allocate(1024);
			QByteArray bytes = QString("/address").toLocal8Bit();
			mBuf->put(&bytes);
		}

		virtual ~TestOscAddress()
		{
			delete mBuf;
		}

		ByteBuffer* mBuf;
	};

	TEST_F(TestOscAddress, isArrayBegin)
	{
		OscAddress osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayBegin());
	}

	TEST_F(TestOscAddress, isArrayEnd)
	{
		OscAddress osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayEnd());
	}

	TEST_F(TestOscAddress, isFalse)
	{
		OscAddress osc(mBuf, 0);
		EXPECT_FALSE(osc.isFalse());
	}

	TEST_F(TestOscAddress, isTrue)
	{
		OscAddress osc(mBuf, 0);
		EXPECT_FALSE(osc.isTrue());
	}

	TEST_F(TestOscAddress, isNil)
	{
		OscAddress osc(mBuf, 0);
		EXPECT_FALSE(osc.isNil());
	}

	TEST_F(TestOscAddress, isInfinitum)
	{
		OscAddress osc(mBuf, 0);
		EXPECT_FALSE(osc.isInfinitum());
	}

	TEST_F(TestOscAddress, toBoolean)
	{
		OscAddress osc(mBuf, 0);
		EXPECT_THROW(osc.toBoolean(), BooleanConversionException);
	}

	TEST_F(TestOscAddress, toBytes)
	{
		OscAddress osc(mBuf, 0);
		EXPECT_THROW(osc.toBytes(), BytesConversionException);
	}

	TEST_F(TestOscAddress, toChar)
	{
		OscAddress osc(mBuf, 0);
		EXPECT_THROW(osc.toChar(), CharConversionException);
	}

	TEST_F(TestOscAddress, toFloat)
	{
		OscAddress osc(mBuf, 0);
		EXPECT_THROW(osc.toFloat(), FloatConversionException);
	}

	TEST_F(TestOscAddress, toDouble)
	{
		OscAddress osc(mBuf, 0);
		EXPECT_THROW(osc.toDouble(), DoubleConversionException);
	}

	TEST_F(TestOscAddress, toInteger)
	{
		OscAddress osc(mBuf, 0);
		EXPECT_THROW(osc.toInteger(), IntegerConversionException);
	}

	TEST_F(TestOscAddress, toLong)
	{
		OscAddress osc(mBuf, 0);
		EXPECT_THROW(osc.toLong(), LongConversionException);
	}

	TEST_F(TestOscAddress, toMIDI)
	{
		OscAddress osc(mBuf, 0);
		EXPECT_THROW(osc.toMIDI(), MidiConversionException);
	}

	TEST_F(TestOscAddress, toRGBA)
	{
		OscAddress osc(mBuf, 0);
		EXPECT_THROW(osc.toRGBA(), RgbaConversionException);
	}

	TEST_F(TestOscAddress, toString)
	{
		OscAddress osc(mBuf, 0);
		EXPECT_EQ(osc.toString(), QString("/address"));
	}

	TEST_F(TestOscAddress, toSymbol)
	{
		OscAddress osc(mBuf, 0);
		EXPECT_EQ(osc.toSymbol(), QChar('\0'));
	}

	TEST_F(TestOscAddress, toTimetag)
	{
		OscAddress osc(mBuf, 0);
		EXPECT_THROW(osc.toTimetag(), TimetagConversionException);
	}

	TEST_F(TestOscAddress, getTag)
	{
		OscAddress osc(mBuf, 0);
		EXPECT_EQ(osc.getTag(), '\0');
	}

}
