#include <osc/composer/OscMessageComposer.h>
#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>
#include <osc/composer/OscMessageComposer.h>
#include <osc/exceptions/OSC_ALL_EXCEPTIONS.h>


namespace {
	class TestOscMessageComposer : public ::testing::Test
	{
	protected:
		TestOscMessageComposer()
			: address("/Ceci est l'adresse")
		{
		}

		virtual ~TestOscMessageComposer()
		{
		}

		QString address;
	};

	TEST_F(TestOscMessageComposer, constructor)
	{
		OscMessageComposer composer(address);
	}

	TEST_F(TestOscMessageComposer, getBytes)
	{
		OscMessageComposer composer(address);
		QByteArray* bytes = composer.getBytes();
		qint32 s = bytes->size();
		EXPECT_EQ(s, 24);
	}

	TEST_F(TestOscMessageComposer, pushArrayBegin)
	{
		OscMessageComposer composer(address);
		composer.pushArrayBegin();
		QByteArray* bytes = composer.getBytes();
		EXPECT_EQ(bytes->size(), 24);
		EXPECT_EQ(bytes->at(21), '[');
		EXPECT_EQ(bytes->at(22), ']');
	}

	TEST_F(TestOscMessageComposer, pushArrayEnd)
	{
		OscMessageComposer composer(address);
		composer.pushArrayEnd();
		QByteArray* bytes = composer.getBytes();
		EXPECT_EQ(bytes->size(), 24);
		EXPECT_EQ(bytes->at(21), '\0');
	}

	TEST_F(TestOscMessageComposer, pushBool_T)
	{
		OscMessageComposer composer(address);
		composer.pushBool(true);
		QByteArray* bytes = composer.getBytes();
		EXPECT_EQ(bytes->size(), 24);
		EXPECT_EQ(bytes->at(21), 'T');
	}

	TEST_F(TestOscMessageComposer, pushBool_F)
	{
		OscMessageComposer composer(address);
		composer.pushBool(false);
		QByteArray* bytes = composer.getBytes();
		EXPECT_EQ(bytes->size(), 24);
		EXPECT_EQ(bytes->at(21), 'F');
	}

	TEST_F(TestOscMessageComposer, pushChar)
	{
		OscMessageComposer composer(address);
		composer.pushChar('~');
		QByteArray* bytes = composer.getBytes();
		EXPECT_EQ(bytes->size(), 28);
		EXPECT_EQ(bytes->at(21), 'c');
	}

	TEST_F(TestOscMessageComposer, pushDouble)
	{
		OscMessageComposer composer(address);
		composer.pushDouble( 321654.64761 );
		QByteArray* bytes = composer.getBytes();
		EXPECT_EQ(bytes->size(), 32);
		EXPECT_EQ(bytes->at(21), 'd');
	}

	TEST_F(TestOscMessageComposer, pushFalse)
	{
		OscMessageComposer composer(address);
		composer.pushFalse();
		QByteArray* bytes = composer.getBytes();
		EXPECT_EQ(bytes->size(), 24);
		EXPECT_EQ(bytes->at(21), 'F');
	}

	TEST_F(TestOscMessageComposer, pushFloat)
	{
		OscMessageComposer composer(address);
		composer.pushFloat(321654.61f);
		QByteArray* bytes = composer.getBytes();
		EXPECT_EQ(bytes->size(), 28);
		EXPECT_EQ(bytes->at(21), 'f');
	}

	TEST_F(TestOscMessageComposer, pushInfinitum)
	{
		OscMessageComposer composer(address);
		composer.pushInfinitum();
		QByteArray* bytes = composer.getBytes();
		EXPECT_EQ(bytes->size(), 24);
		EXPECT_EQ(bytes->at(21), 'I');
	}

	TEST_F(TestOscMessageComposer, pushInt32)
	{
		OscMessageComposer composer(address);
		composer.pushInt32( 321654 );
		QByteArray* bytes = composer.getBytes();
		EXPECT_EQ(bytes->size(), 28);
		EXPECT_EQ(bytes->at(21), 'i');
	}

	TEST_F(TestOscMessageComposer, pushLong)
	{
		OscMessageComposer composer(address);
		composer.pushLong(121212155588);
		QByteArray* bytes = composer.getBytes();
		EXPECT_EQ(bytes->size(), 32);
		EXPECT_EQ(bytes->at(21), 'h');
	}

	TEST_F(TestOscMessageComposer, pushMidi)
	{
		OscMessageComposer composer(address);
		composer.pushMidi('1', '2', 'e', 'r' );
		QByteArray* bytes = composer.getBytes();
		EXPECT_EQ(bytes->size(), 28);
		EXPECT_EQ(bytes->at(21), 'm');
	}

	TEST_F(TestOscMessageComposer, pushNil_)
	{
		OscMessageComposer composer(address);
		composer.pushNil();
		QByteArray* bytes = composer.getBytes();
		EXPECT_EQ(bytes->size(), 24);
		EXPECT_EQ(bytes->at(21), 'N');
	}

	TEST_F(TestOscMessageComposer, pushRGBA)
	{
		OscMessageComposer composer(address);
		composer.pushRGBA( 0x12568987 );
		QByteArray* bytes = composer.getBytes();
		EXPECT_EQ(bytes->size(), 28);
		EXPECT_EQ(bytes->at(21), 'r');
	}

	TEST_F(TestOscMessageComposer, pushString)
	{
		OscMessageComposer composer(address);
		QString str("Hello");
		composer.pushString( str );
		QByteArray* bytes = composer.getBytes();
		EXPECT_EQ(bytes->size(), 32);
		EXPECT_EQ(bytes->at(21), 's');
	}

	TEST_F(TestOscMessageComposer, pushSymbol)
	{
		OscMessageComposer composer(address);
		QString str("Hello");
		composer.pushSymbol(str);
		QByteArray* bytes = composer.getBytes();
		EXPECT_EQ(bytes->size(), 32);
		EXPECT_EQ(bytes->at(21), 'S');
	}

	TEST_F(TestOscMessageComposer, pushTimeTag)
	{
		OscMessageComposer composer(address);
		NtpTimestamp ntp( 0x12345678, 0x90125487);
		QDateTime time = NtpTimestamp::toDateTime( ntp );
		composer.pushTimeTag( time );
		QByteArray* bytes = composer.getBytes();
		EXPECT_EQ(bytes->size(), 32);
		EXPECT_EQ(bytes->at(21), 't');
	}

	TEST_F(TestOscMessageComposer, pushTrue)
	{
		OscMessageComposer composer(address);
		composer.pushTrue();
		QByteArray* bytes = composer.getBytes();
		EXPECT_EQ(bytes->size(), 24);
		EXPECT_EQ(bytes->at(21), 'T');
	}

	TEST_F(TestOscMessageComposer, testAddress)
	{
		address = "/protocol/discover/42787";
		OscMessageComposer composer(address);
		QByteArray* bytes = composer.getBytes();
		EXPECT_EQ(bytes->size(), 32);
	}
}
