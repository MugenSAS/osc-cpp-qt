#include <osc/composer/OscMessageComposer.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/reader/types/OscSymbol.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>


namespace {
	// The fixture for testing class ByteBuffer.
	class TestOscSymbol : public ::testing::Test {
	protected:
		TestOscSymbol()
			: mValue("Hello")
		{
			mBuf = ByteBuffer::allocate(1024);
			QByteArray bytes = mValue.toLocal8Bit();
			mBuf->put(&bytes);
		}

		virtual ~TestOscSymbol()
		{
			delete mBuf;
		}

		ByteBuffer* mBuf;
		QString mValue;
	};

	TEST_F(TestOscSymbol, isArrayBegin)
	{
		OscSymbol osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayBegin());
	}

	TEST_F(TestOscSymbol, isArrayEnd)
	{
		OscSymbol osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayEnd());
	}

	TEST_F(TestOscSymbol, isFalse)
	{
		OscSymbol osc(mBuf, 0);
		EXPECT_FALSE(osc.isFalse());
	}

	TEST_F(TestOscSymbol, isTrue)
	{
		OscSymbol osc(mBuf, 0);
		EXPECT_FALSE(osc.isTrue());
	}

	TEST_F(TestOscSymbol, isNil)
	{
		OscSymbol osc(mBuf, 0);
		EXPECT_FALSE(osc.isNil());
	}

	TEST_F(TestOscSymbol, isInfinitum)
	{
		OscSymbol osc(mBuf, 0);
		EXPECT_FALSE(osc.isInfinitum());
	}

	TEST_F(TestOscSymbol, toBoolean)
	{
		OscSymbol osc(mBuf, 0);
		EXPECT_TRUE(osc.toBoolean());
	}

	TEST_F(TestOscSymbol, toBytes)
	{
		OscSymbol osc(mBuf, 0);
		EXPECT_EQ(osc.toBytes(), mValue.toLocal8Bit());
	}

	TEST_F(TestOscSymbol, toChar)
	{
		OscSymbol osc(mBuf, 0);
		EXPECT_THROW(osc.toChar(), CharConversionException);
	}

	TEST_F(TestOscSymbol, toFloat)
	{
		mValue = "12.365";
		bool ok;
		float f = mValue.toFloat(&ok);
		mBuf->setPosition(0);
		QByteArray bytes = mValue.toLocal8Bit();
		mBuf->put(&bytes);
		mBuf->put('\0');

		OscSymbol osc(mBuf, 0);
		EXPECT_FLOAT_EQ(osc.toFloat(), f);
	}

	TEST_F(TestOscSymbol, toDouble)
	{
		mValue = "12.356";
		mBuf->setPosition(0);
		QByteArray bytes = mValue.toLocal8Bit();
		mBuf->put(&bytes);
		OscSymbol osc(mBuf, 0);
		bool ok;
		double d = mValue.toDouble(&ok);
		EXPECT_DOUBLE_EQ(osc.toDouble(), d);
	}

	TEST_F(TestOscSymbol, toInteger)
	{
		mValue = "125468";
		bool ok;
		qint32 i = mValue.toInt(&ok);
		mBuf->setPosition(0);
		QByteArray bytes = mValue.toLocal8Bit();
		mBuf->put(&bytes);
		mBuf->put('\0');
		OscSymbol osc(mBuf, 0);
		EXPECT_DOUBLE_EQ(osc.toInteger(), i);
	}

	TEST_F(TestOscSymbol, toLong)
	{
		mValue = "125468";
		bool ok;
		qint64 h = mValue.toLongLong(&ok);
		mBuf->setPosition(0);
		QByteArray bytes = mValue.toLocal8Bit();
		mBuf->put(&bytes);
		mBuf->put('\0');
		OscSymbol osc(mBuf, 0);
		EXPECT_DOUBLE_EQ(osc.toLong(), h);
	}

	TEST_F(TestOscSymbol, toMIDI)
	{
		OscSymbol osc(mBuf, 0);
		EXPECT_THROW(osc.toMIDI(), MidiConversionException);
	}

	TEST_F(TestOscSymbol, toRGBA)
	{
		OscSymbol osc(mBuf, 0);
		EXPECT_THROW(osc.toRGBA(), RgbaConversionException);

	}

	TEST_F(TestOscSymbol, toString)
	{
		OscSymbol osc(mBuf, 0);
		EXPECT_EQ(osc.toString(), mValue);
	}

	TEST_F(TestOscSymbol, toSymbol)
	{
		OscSymbol osc(mBuf, 0);
		EXPECT_EQ(osc.toSymbol(), mValue);
	}

	TEST_F(TestOscSymbol, toTimetag)
	{
		OscSymbol osc(mBuf, 0);
		EXPECT_THROW(osc.toTimetag(), TimetagConversionException);
	}

	TEST_F(TestOscSymbol, getTag)
	{
		OscSymbol osc(mBuf, 0);
		EXPECT_EQ(osc.getTag(), 'S');
	}

}
