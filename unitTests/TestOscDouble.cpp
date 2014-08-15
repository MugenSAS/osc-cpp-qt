#include <osc/composer/OscMessageComposer.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/reader/types/OscDouble.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>
#include <tools/NtpTimestamp.h>


namespace {
	// The fixture for testing class ByteBuffer.
	class TestOscDouble : public ::testing::Test {
	protected:
		TestOscDouble()
			: mValue(1259321.216843)
		{
			mBuf = ByteBuffer::allocate(1024);
			mBuf->putDouble(mValue);
		}

		virtual ~TestOscDouble()
		{
			delete mBuf;
		}

		ByteBuffer* mBuf;
		double mValue;
	};

	TEST_F(TestOscDouble, isArrayBegin)
	{
		OscDouble osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayBegin());
	}

	TEST_F(TestOscDouble, isArrayEnd)
	{
		OscDouble osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayEnd());
	}

	TEST_F(TestOscDouble, isFalse)
	{
		OscDouble osc(mBuf, 0);
		EXPECT_FALSE(osc.isFalse());
	}

	TEST_F(TestOscDouble, isTrue)
	{
		OscDouble osc(mBuf, 0);
		EXPECT_FALSE(osc.isTrue());
	}

	TEST_F(TestOscDouble, isNil)
	{
		OscDouble osc(mBuf, 0);
		EXPECT_FALSE(osc.isNil());
	}

	TEST_F(TestOscDouble, isInfinitum)
	{
		OscDouble osc(mBuf, 0);
		EXPECT_FALSE(osc.isInfinitum());
	}

	TEST_F(TestOscDouble, toBoolean)
	{
		OscDouble osc(mBuf, 0);
		EXPECT_TRUE(osc.toBoolean());
	}

	TEST_F(TestOscDouble, toBytes)
	{
		OscDouble osc(mBuf, 0);
		QByteArray bytes(8, 0);
		bytes.insert(0, (char*)&mValue, 8);
		EXPECT_EQ(osc.toBytes(), bytes);
	}

	TEST_F(TestOscDouble, toChar)
	{
		OscDouble osc(mBuf, 0);
		EXPECT_THROW(osc.toChar(), CharConversionException);
	}

	TEST_F(TestOscDouble, toFloat)
	{
		OscDouble osc(mBuf, 0);
		EXPECT_FLOAT_EQ(osc.toFloat(), mValue);
	}

	TEST_F(TestOscDouble, toDouble)
	{
		OscDouble osc(mBuf, 0);
		EXPECT_DOUBLE_EQ(osc.toDouble(), mValue);
	}

	TEST_F(TestOscDouble, toInteger)
	{
		OscDouble osc(mBuf, 0);
		EXPECT_EQ(osc.toInteger(), (qint32)mValue);
	}

	TEST_F(TestOscDouble, toLong)
	{
		OscDouble osc(mBuf, 0);
		EXPECT_EQ(osc.toLong(), (qint64)mValue);
	}

	TEST_F(TestOscDouble, toMIDI)
	{
		OscDouble osc(mBuf, 0);
		QByteArray bytes(8, 0);
		bytes.insert(0, (char*)&mValue, 8);
		EXPECT_EQ(osc.toMIDI(), Midi(bytes));
	}

	TEST_F(TestOscDouble, toRGBA)
	{
		OscDouble osc(mBuf, 0);
		QByteArray bytes(8, 0);
		bytes.insert(0, (char*)&mValue, 8);
		EXPECT_EQ(osc.toRGBA(), RGBA(bytes));
	}

	TEST_F(TestOscDouble, toString)
	{
		OscDouble osc(mBuf, 0);
		EXPECT_EQ(osc.toString(), QString::number(mValue));
	}

	TEST_F(TestOscDouble, toSymbol)
	{
		OscDouble osc(mBuf, 0);
		EXPECT_EQ(osc.toSymbol(), QChar('d'));
	}

	TEST_F(TestOscDouble, toTimetag)
	{
		OscDouble osc(mBuf, 0);
		QByteArray bytes(8, 0);
		bytes.insert(0, (char*)&mValue, 8);
		NtpTimestamp ntp( *(qint32*)bytes.constData(), *(qint32*)(bytes.constData() + 4) );
		EXPECT_EQ(osc.toTimetag(), NtpTimestamp::toDateTime(ntp));
	}

	TEST_F(TestOscDouble, getTag)
	{
		OscDouble osc(mBuf, 0);
		EXPECT_EQ(osc.getTag(), 'd');
	}

}
