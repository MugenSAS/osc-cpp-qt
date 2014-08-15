#include <osc/composer/OscMessageComposer.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/reader/types/OscLong.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>


namespace {
	// The fixture for testing class ByteBuffer.
	class TestOscLong : public ::testing::Test {
	protected:
		TestOscLong()
			: mValue(65487654654)
		{
			mBuf = ByteBuffer::allocate(1024);
			mBuf->putLong(mValue);
		}

		virtual ~TestOscLong()
		{
			delete mBuf;
		}

		ByteBuffer* mBuf;
		qint64 mValue;
	};

	TEST_F(TestOscLong, isArrayBegin)
	{
		OscLong osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayBegin());
	}

	TEST_F(TestOscLong, isArrayEnd)
	{
		OscLong osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayEnd());
	}

	TEST_F(TestOscLong, isFalse)
	{
		OscLong osc(mBuf, 0);
		EXPECT_FALSE(osc.isFalse());
	}

	TEST_F(TestOscLong, isTrue)
	{
		OscLong osc(mBuf, 0);
		EXPECT_FALSE(osc.isTrue());
	}

	TEST_F(TestOscLong, isNil)
	{
		OscLong osc(mBuf, 0);
		EXPECT_FALSE(osc.isNil());
	}

	TEST_F(TestOscLong, isInfinitum)
	{
		OscLong osc(mBuf, 0);
		EXPECT_FALSE(osc.isInfinitum());
	}

	TEST_F(TestOscLong, toBoolean)
	{
		OscLong osc(mBuf, 0);
		EXPECT_TRUE(osc.toBoolean());
	}

	TEST_F(TestOscLong, toBytes)
	{
		OscLong osc(mBuf, 0);
		QByteArray bytes(8, 0);
		bytes.insert(0, (char*)&mValue, 8);
		EXPECT_EQ(osc.toBytes(), bytes);
	}

	TEST_F(TestOscLong, toChar)
	{
		OscLong osc(mBuf, 0);
		EXPECT_THROW(osc.toChar(), CharConversionException);
	}

	TEST_F(TestOscLong, toFloat)
	{
		OscLong osc(mBuf, 0);
		EXPECT_FLOAT_EQ(osc.toFloat(), (float)mValue);
	}

	TEST_F(TestOscLong, toDouble)
	{
		OscLong osc(mBuf, 0);
		EXPECT_DOUBLE_EQ(osc.toDouble(), (double)mValue);
	}

	TEST_F(TestOscLong, toInteger)
	{
		OscLong osc(mBuf, 0);
		EXPECT_EQ(osc.toInteger(), (qint32)mValue);
	}

	TEST_F(TestOscLong, toLong)
	{
		OscLong osc(mBuf, 0);
		EXPECT_EQ(osc.toLong(), mValue);
	}

	TEST_F(TestOscLong, toMIDI)
	{
		OscLong osc(mBuf, 0);
		QByteArray bytes(8, 0);
		bytes.insert(0, (char*)&mValue, 8);
		EXPECT_EQ(osc.toMIDI(), Midi(bytes));
	}

	TEST_F(TestOscLong, toRGBA)
	{
		OscLong osc(mBuf, 0);
		QByteArray bytes(8, 0);
		bytes.insert(0, (char*)&mValue, 8);
		EXPECT_EQ(osc.toRGBA(), RGBA(bytes));
	}

	TEST_F(TestOscLong, toString)
	{
		OscLong osc(mBuf, 0);
		EXPECT_EQ(osc.toString(), QString::number(mValue));
	}

	TEST_F(TestOscLong, toSymbol)
	{
		OscLong osc(mBuf, 0);
		EXPECT_EQ(osc.toSymbol(), QChar('h'));
	}

	TEST_F(TestOscLong, toTimetag)
	{
		OscLong osc(mBuf, 0);
		QByteArray bytes(8, 0);
		bytes.insert(0, (char*)&mValue, 8);
		NtpTimestamp ntp( *(qint32*)bytes.constData(), *(qint32*)(bytes.constData() + 4) );
		EXPECT_EQ(osc.toTimetag(), NtpTimestamp::toDateTime(ntp));
	}

	TEST_F(TestOscLong, getTag)
	{
		OscLong osc(mBuf, 0);
		EXPECT_EQ(osc.getTag(), 'h');
	}

}
