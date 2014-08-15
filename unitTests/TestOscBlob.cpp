#include <osc/composer/OscMessageComposer.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/reader/types/OscBlob.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>


namespace {
	// The fixture for testing class ByteBuffer.
	class TestOscBlob : public ::testing::Test {
	protected:
		TestOscBlob()
		{
			mBuf = ByteBuffer::allocate(1024);
			mBuf->putInt(4);
			mBuf->putChar(0x55);
			mBuf->putChar(0x11);
			mBuf->putChar(0x22);
			mBuf->putChar(0x33);
		}

		virtual ~TestOscBlob()
		{
			delete mBuf;
		}

		ByteBuffer* mBuf;
	};

	TEST_F(TestOscBlob, isArrayBegin)
	{
		OscBlob osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayBegin());
	}

	TEST_F(TestOscBlob, isArrayEnd)
	{
		OscBlob osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayEnd());
	}

	TEST_F(TestOscBlob, isFalse)
	{
		OscBlob osc(mBuf, 0);
		EXPECT_FALSE(osc.isFalse());
	}

	TEST_F(TestOscBlob, isTrue)
	{
		OscBlob osc(mBuf, 0);
		EXPECT_FALSE(osc.isTrue());
	}

	TEST_F(TestOscBlob, isNil)
	{
		OscBlob osc(mBuf, 0);
		EXPECT_FALSE(osc.isNil());
	}

	TEST_F(TestOscBlob, isInfinitum)
	{
		OscBlob osc(mBuf, 0);
		EXPECT_FALSE(osc.isInfinitum());
	}

	TEST_F(TestOscBlob, toBoolean)
	{
		OscBlob osc(mBuf, 0);
		EXPECT_TRUE(osc.toBoolean());
	}

	TEST_F(TestOscBlob, toBytes)
	{
		OscBlob osc(mBuf, 0);
		QByteArray bytes;
		bytes.append(0x55);
		bytes.append(0x11);
		bytes.append(0x22);
		bytes.append(0x33);
		const char* data1 = osc.toBytes().constData();
		const char* data2 = bytes.constData();

		EXPECT_TRUE(memcmp(data1, data2, 4) == 0);
	}

	TEST_F(TestOscBlob, toChar)
	{
		OscBlob osc(mBuf, 0);
		EXPECT_THROW(osc.toChar(), CharConversionException);
	}

	TEST_F(TestOscBlob, toFloat)
	{
		OscBlob osc(mBuf, 0);
		EXPECT_THROW(osc.toFloat(), FloatConversionException);
	}

	TEST_F(TestOscBlob, toDouble)
	{
		OscBlob osc(mBuf, 0);
		EXPECT_THROW(osc.toDouble(), DoubleConversionException);
	}

	TEST_F(TestOscBlob, toInteger)
	{
		OscBlob osc(mBuf, 0);
		EXPECT_THROW(osc.toInteger(), IntegerConversionException);
	}

	TEST_F(TestOscBlob, toLong)
	{
		OscBlob osc(mBuf, 0);
		EXPECT_THROW(osc.toLong(), LongConversionException);
	}

	TEST_F(TestOscBlob, toMIDI)
	{
		OscBlob osc(mBuf, 0);
		EXPECT_THROW(osc.toMIDI(), MidiConversionException);
	}

	TEST_F(TestOscBlob, toRGBA)
	{
		OscBlob osc(mBuf, 0);
		EXPECT_THROW(osc.toRGBA(), RgbaConversionException);
	}

	TEST_F(TestOscBlob, toString)
	{
		OscBlob osc(mBuf, 0);
		EXPECT_THROW(osc.toString(), StringConversionException);
	}

	TEST_F(TestOscBlob, toSymbol)
	{
		OscBlob osc(mBuf, 0);
		EXPECT_EQ(osc.toSymbol(), QChar('b') );
	}

	TEST_F(TestOscBlob, toTimetag)
	{
		OscBlob osc(mBuf, 0);
		EXPECT_THROW(osc.toTimetag(), TimetagConversionException);
	}

	TEST_F(TestOscBlob, getTag)
	{
		OscBlob osc(mBuf, 0);
		EXPECT_EQ(osc.getTag(), 'b');
	}

}
