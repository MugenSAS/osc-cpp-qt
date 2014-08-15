#include <osc/composer/OscMessageComposer.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/reader/types/OscString.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>


namespace {
	// The fixture for testing class ByteBuffer.
	class TestOscString : public ::testing::Test {
	protected:
		TestOscString()
			: mValue("Hello")
		{
			mBuf = ByteBuffer::allocate(1024);
			QByteArray bytes = mValue.toUtf8();
			mBuf->put(&bytes);
		}

		virtual ~TestOscString()
		{
			delete mBuf;
		}

		ByteBuffer* mBuf;
		QString mValue;
	};

	TEST_F(TestOscString, isArrayBegin)
	{
		OscString osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayBegin());
	}

	TEST_F(TestOscString, isArrayEnd)
	{
		OscString osc(mBuf, 0);
		EXPECT_FALSE(osc.isArrayEnd());
	}

	TEST_F(TestOscString, isFalse)
	{
		OscString osc(mBuf, 0);
		EXPECT_FALSE(osc.isFalse());
	}

	TEST_F(TestOscString, isTrue)
	{
		OscString osc(mBuf, 0);
		EXPECT_FALSE(osc.isTrue());
	}

	TEST_F(TestOscString, isNil)
	{
		OscString osc(mBuf, 0);
		EXPECT_FALSE(osc.isNil());
	}

	TEST_F(TestOscString, isInfinitum)
	{
		OscString osc(mBuf, 0);
		EXPECT_FALSE(osc.isInfinitum());
	}

	TEST_F(TestOscString, toBoolean)
	{
		OscString osc(mBuf, 0);
		EXPECT_TRUE(osc.toBoolean());
	}

	TEST_F(TestOscString, toBytes)
	{
		OscString osc(mBuf, 0);
		EXPECT_EQ(osc.toBytes(), mValue.toUtf8());
	}

	TEST_F(TestOscString, toChar)
	{
		OscString osc(mBuf, 0);
		EXPECT_THROW(osc.toChar(), CharConversionException);
	}

	TEST_F(TestOscString, toFloat)
	{
		mValue = "12.365";
		bool ok;
		float f = mValue.toFloat(&ok);
		mBuf->setPosition(0);
		QByteArray bytes = mValue.toUtf8();
		mBuf->put(&bytes);
		mBuf->put('\0');

		OscString osc(mBuf, 0);
		EXPECT_FLOAT_EQ(osc.toFloat(), f);
	}

	TEST_F(TestOscString, toDouble)
	{
		mValue = "12.356";
		mBuf->setPosition(0);
		QByteArray bytes = mValue.toUtf8();
		mBuf->put(&bytes);
		OscString osc(mBuf, 0);
		bool ok;
		double d = mValue.toDouble(&ok);
		EXPECT_DOUBLE_EQ(osc.toDouble(), d);
	}

	TEST_F(TestOscString, toInteger)
	{
		mValue = "125468";
		bool ok;
		qint32 i = mValue.toInt(&ok);
		mBuf->setPosition(0);
		QByteArray bytes = mValue.toUtf8();
		mBuf->put(&bytes);
		mBuf->put('\0');
		OscString osc(mBuf, 0);
		EXPECT_DOUBLE_EQ(osc.toInteger(), i);
	}

	TEST_F(TestOscString, toLong)
	{
		mValue = "125468";
		bool ok;
		qint64 h = mValue.toLongLong(&ok);
		mBuf->setPosition(0);
		QByteArray bytes = mValue.toUtf8();
		mBuf->put(&bytes);
		mBuf->put('\0');
		OscString osc(mBuf, 0);
		EXPECT_DOUBLE_EQ(osc.toLong(), h);
	}

	TEST_F(TestOscString, toMIDI)
	{
		OscString osc(mBuf, 0);
		EXPECT_THROW(osc.toMIDI(), MidiConversionException);
	}

	TEST_F(TestOscString, toRGBA)
	{
		OscString osc(mBuf, 0);
		EXPECT_THROW(osc.toRGBA(), RgbaConversionException);

	}

	TEST_F(TestOscString, toString)
	{
		OscString osc(mBuf, 0);
		EXPECT_EQ(osc.toString(), mValue);
	}

	TEST_F(TestOscString, toSymbol)
	{
		OscString osc(mBuf, 0);
		EXPECT_EQ(osc.toSymbol(), mValue);
	}

	TEST_F(TestOscString, toTimetag)
	{
		OscString osc(mBuf, 0);
		EXPECT_THROW(osc.toTimetag(), TimetagConversionException);
	}

	TEST_F(TestOscString, getTag)
	{
		OscString osc(mBuf, 0);
		EXPECT_EQ(osc.getTag(), 's');
	}

}
