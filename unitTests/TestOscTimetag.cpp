#include <osc/composer/OscMessageComposer.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/reader/types/OscTimetag.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>
#include <tools/NtpTimestamp.h>
#include <QtEndian>

namespace {
	// The fixture for testing class ByteBuffer.
	class TestOscTimetag : public ::testing::Test {
	protected:
		TestOscTimetag()
		{
			mValue.setSeconds(125);
			mValue.setFraction(1425);
			mBuf = ByteBuffer::allocate(1024);
			mBuf->putInt(125);
			mBuf->putInt(1425);
		}

		virtual ~TestOscTimetag()
		{
			delete mBuf;
		}

		ByteBuffer* mBuf;
		NtpTimestamp mValue;
	};

	TEST_F(TestOscTimetag, isArrayBegin)
	{
		OscTimetag osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayBegin());
	}

	TEST_F(TestOscTimetag, isArrayEnd)
	{
		OscTimetag osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayEnd());
	}

	TEST_F(TestOscTimetag, isFalse)
	{
		OscTimetag osc(mBuf, 0);
		EXPECT_FALSE(osc.isFalse());
	}

	TEST_F(TestOscTimetag, isTrue)
	{
		OscTimetag osc(mBuf, 0);
		EXPECT_FALSE(osc.isTrue());
	}

	TEST_F(TestOscTimetag, isNil)
	{
		OscTimetag osc(mBuf, 0);
		EXPECT_FALSE(osc.isNil());
	}

	TEST_F(TestOscTimetag, isInfinitum)
	{
		OscTimetag osc(mBuf, 0);
		EXPECT_FALSE(osc.isInfinitum());
	}

	TEST_F(TestOscTimetag, toBoolean)
	{
		OscTimetag osc(mBuf, 0);
		EXPECT_TRUE(osc.toBoolean());
	}

	TEST_F(TestOscTimetag, toBytes)
	{
		OscTimetag osc(mBuf, 0);
		QByteArray bytes(8, 0);
		quint32 secs = qToBigEndian(125);
		quint32 fracs = qToBigEndian(1425);
		bytes.insert(0, (char*)&secs, 4);
		bytes.insert(4, (char*)&fracs, 4);
		EXPECT_EQ(osc.toBytes(), bytes);
	}

	TEST_F(TestOscTimetag, toChar)
	{
		OscTimetag osc(mBuf, 0);
		EXPECT_THROW(osc.toChar(), CharConversionException);
	}

	TEST_F(TestOscTimetag, toFloat)
	{
		OscTimetag osc(mBuf, 0);
		EXPECT_THROW(osc.toFloat(), FloatConversionException);
	}

	TEST_F(TestOscTimetag, toDouble)
	{
		OscTimetag osc(mBuf, 0);
		EXPECT_THROW(osc.toDouble(), DoubleConversionException);
	}

	TEST_F(TestOscTimetag, toInteger)
	{
		OscTimetag osc(mBuf, 0);
		EXPECT_THROW(osc.toInteger(), IntegerConversionException);
	}

	TEST_F(TestOscTimetag, toLong)
	{
		OscTimetag osc(mBuf, 0);
		EXPECT_THROW(osc.toLong(), LongConversionException);
	}

	TEST_F(TestOscTimetag, toMIDI)
	{
		OscTimetag osc(mBuf, 0);
		QByteArray bytes(4, 0);
		quint32 secs = 125;
		bytes.insert(0, (char*)&secs, 4);
		EXPECT_EQ(osc.toMIDI(), Midi(bytes));
	}

	TEST_F(TestOscTimetag, toRGBA)
	{
		OscTimetag osc(mBuf, 0);
		QByteArray bytes(4, 0);
		quint32 secs = 125;
		bytes.insert(0, (char*)&secs, 4);
		EXPECT_EQ(osc.toRGBA(), RGBA(bytes));
	}

	TEST_F(TestOscTimetag, toString)
	{
		OscTimetag osc(mBuf, 0);
		EXPECT_THROW(osc.toString(), StringConversionException);
	}

	TEST_F(TestOscTimetag, toSymbol)
	{
		OscTimetag osc(mBuf, 0);
		EXPECT_EQ(osc.toSymbol(), QChar('t'));
	}

	TEST_F(TestOscTimetag, toTimetag)
	{
		OscTimetag osc(mBuf, 0);
		EXPECT_EQ(osc.toTimetag(), NtpTimestamp::toDateTime(mValue) );
	}

	TEST_F(TestOscTimetag, getTag)
	{
		OscTimetag osc(mBuf, 0);
		EXPECT_EQ(osc.getTag(), 't');
	}

}
