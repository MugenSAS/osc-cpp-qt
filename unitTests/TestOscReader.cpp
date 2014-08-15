#include <osc/reader/OscReader.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/composer/OscMessageComposer.h>
#include <osc/reader/OscMessage.h>
#include <osc/reader/types/OscValue.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>


namespace {
	class TestOscReader : public ::testing::Test
	{
	protected:
		TestOscReader()
		{
			QString address("/Ceci est l'adresse");
			mComposer = new OscMessageComposer(address);
			mComposer->pushArrayBegin();	// 1
			mComposer->pushBool(true);		// 2
			mComposer->pushChar('#');		// 3
			mComposer->pushDouble(3215.659);	// 4
			mComposer->pushFalse();				// 5
			mComposer->pushFloat(1.25f);		// 6
			mComposer->pushInfinitum();			// 7
			mComposer->pushInt32(321564);		// 8
			mComposer->pushLong((qint64)87654321654);	// 9
			mComposer->pushMidi(1, 2, 3, 4);	// 10
			mComposer->pushNil();				// 11
			mComposer->pushRGBA(0x21326554);	// 12
			QString str("Hello");
			mComposer->pushString(str);	// 13
			mComposer->pushSymbol(str);	// 14

			mTime.setTime( QTime::currentTime() );
			mComposer->pushTimeTag(mTime);	// 15

			mComposer->pushTrue();						// 16
			mReader = new OscReader(mComposer->getBytes());
			mMessage = mReader->getMessage();
		}

		virtual ~TestOscReader()
		{
			delete mComposer;
		}


		OscMessageComposer* mComposer;
		OscReader* mReader;
		OscMessage* mMessage;
		QDateTime mTime;
	};

	TEST_F(TestOscReader, readArrayBegin)
	{
		OscValue* value = mMessage->getValue(0);
		EXPECT_TRUE( value->isArrayBegin() );
	}

	TEST_F(TestOscReader, readArrayEnd)
	{
		OscValue* value = mMessage->getValue(16);
		EXPECT_TRUE(value->isArrayEnd());
	}

	TEST_F(TestOscReader, readChar)
	{
		OscValue* value = mMessage->getValue(2);
		EXPECT_EQ(value->toChar(), '#');
	}

	TEST_F(TestOscReader, readDouble)
	{
		OscValue* value = mMessage->getValue(3);
		EXPECT_DOUBLE_EQ(value->toDouble(), 3215.659);
	}

	TEST_F(TestOscReader, readFalse)
	{
		OscValue* value = mMessage->getValue(4);
		EXPECT_TRUE(value->isFalse());
	}

	TEST_F(TestOscReader, readFloat)
	{
		OscValue* value = mMessage->getValue(5);
		EXPECT_FLOAT_EQ(value->toFloat(), 1.25f);
	}

	TEST_F(TestOscReader, readInfinitum)
	{
		OscValue* value = mMessage->getValue(6);
		EXPECT_TRUE(value->isInfinitum());
	}

	TEST_F(TestOscReader, readInt32)
	{
		OscValue* value = mMessage->getValue(7);
		EXPECT_EQ(value->toInteger(), 321564);
	}

	TEST_F(TestOscReader, readLong)
	{
		OscValue* value = mMessage->getValue(8);
		EXPECT_EQ(value->toLong(), 87654321654);
	}

	TEST_F(TestOscReader, readMidi)
	{
		OscValue* value = mMessage->getValue(9);
		EXPECT_EQ(value->toMIDI(), Midi(1, 2, 3, 4));
	}

	TEST_F(TestOscReader, readNil_)
	{
		OscValue* value = mMessage->getValue(10);
		EXPECT_TRUE(value->isNil());
	}

	TEST_F(TestOscReader, readRGBA)
	{
		OscValue* value = mMessage->getValue(11);
		EXPECT_EQ(value->toRGBA(), RGBA(0x21326554));
	}

	TEST_F(TestOscReader, readString)
	{
		OscValue* value = mMessage->getValue(12);
		EXPECT_EQ(value->toString(), QString("Hello"));
	}

	TEST_F(TestOscReader, readSymbol)
	{
		OscValue* value = mMessage->getValue(13);
		EXPECT_EQ(value->toSymbol(), QString("Hello"));
	}

	TEST_F(TestOscReader, readTimeTag)
	{
		OscValue* value = mMessage->getValue(14);
		QDateTime time = value->toTimetag();
		qint64 msec0 = time.toMSecsSinceEpoch();
		qint64 msec1 = mTime.toMSecsSinceEpoch();
		EXPECT_TRUE( abs(msec1 - msec0) < 10 );
	}

	TEST_F(TestOscReader, readTrue)
	{
		OscValue* value = mMessage->getValue(15);
		EXPECT_TRUE(value->isTrue());
	}
}
