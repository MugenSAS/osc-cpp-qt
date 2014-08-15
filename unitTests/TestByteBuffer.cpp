#include <tools/ByteBuffer.h>
#include <gtest/gtest.h>
#include <QtCore/QString>

namespace {
	// The fixture for testing class ByteBuffer.
	class TestByteBuffer : public ::testing::Test {
	protected:
		TestByteBuffer()
		{
		}

		virtual ~TestByteBuffer()
		{
		}
	};

	// Tests that the ByteBuffer::allocate() creates a properly formatted buffer
	TEST_F(TestByteBuffer, allocate)
	{
		ByteBuffer* buf = ByteBuffer::allocate(1024);
		EXPECT_TRUE(buf->getCapacity() == 1024);
		EXPECT_TRUE(buf->getPosition() == 0);
		EXPECT_TRUE(buf->getRemaining() == 1024);
		EXPECT_TRUE(buf->getOrder() == ByteOrder::BIG_ENDIAN_DATA);
		delete buf;
	}

	// Tests that the ByteBuffer:setOrder() sets properly the byte ordering property
	TEST_F(TestByteBuffer, order)
	{
		ByteBuffer* buf = ByteBuffer::allocate(1024);
		buf->setOrder(ByteOrder::BIG_ENDIAN_DATA);
		EXPECT_TRUE(buf->getOrder() == ByteOrder::BIG_ENDIAN_DATA);
		buf->setOrder(ByteOrder::LITTLE_ENDIAN_DATA);
		EXPECT_TRUE(buf->getOrder() == ByteOrder::LITTLE_ENDIAN_DATA);
		delete buf;
	}

	// Tests that the ByteBuffer::putChar()/getChar() push and get data properly
	TEST_F(TestByteBuffer, putChar)
	{
		ByteBuffer* buf = ByteBuffer::allocate(1024);
		buf->putChar('A');
		EXPECT_TRUE(buf->getPosition() == 1);
		buf->setPosition(0);
		EXPECT_TRUE( buf->getChar() == 'A' );
		delete buf;
	}

	// Tests that the ByteBuffer::putDouble()/getDouble() push and get data properly
	TEST_F(TestByteBuffer, putDouble)
	{
		ByteBuffer* buf = ByteBuffer::allocate(1024);
		buf->putDouble(154321.259456);
		EXPECT_TRUE(buf->getPosition() == 8);
		buf->setPosition(0);
		EXPECT_TRUE(buf->getDouble() == 154321.259456);
		delete buf;
	}
	
	// Tests that the ByteBuffer::putFloat()/getFloat() push and get data properly
	TEST_F(TestByteBuffer, putFloat)
	{
		ByteBuffer* buf = ByteBuffer::allocate(1024);
		buf->putFloat(1521.256f);
		EXPECT_TRUE(buf->getPosition() == 4);
		buf->setPosition(0);
		EXPECT_TRUE(buf->getFloat() == 1521.256f);
		delete buf;
	}
	
	// Tests that the ByteBuffer::putInt()/getInt() push and get data properly
	TEST_F(TestByteBuffer, putInt)
	{
		ByteBuffer* buf = ByteBuffer::allocate(1024);
		buf->putInt(0x6549365);
		EXPECT_TRUE(buf->getPosition() == 4);
		buf->setPosition(0);
		EXPECT_TRUE(buf->getInt() == 0x6549365);
		delete buf;
	}
	
	// Tests that the ByteBuffer::putLong()/getLong() push and get data properly
	TEST_F(TestByteBuffer, putLong)
	{
		ByteBuffer* buf = ByteBuffer::allocate(1024);
		buf->putLong(0x6549879812365);
		EXPECT_TRUE(buf->getPosition() == 8);
		buf->setPosition(0);
		EXPECT_TRUE(buf->getLong() == 0x6549879812365);
		delete buf;
	}


	// Tests that the ByteBuffer::putShort()/getShort() push and get data properly
	TEST_F(TestByteBuffer, putShort)
	{
		ByteBuffer* buf = ByteBuffer::allocate(1024);
		buf->putShort(0x6549);
		EXPECT_TRUE(buf->getPosition() == 2);
		buf->setPosition(0);
		EXPECT_TRUE(buf->getShort() == 0x6549);
		delete buf;
	}

	// Tests that the ByteBuffer::putShort()/getShort() push and get data properly
	TEST_F(TestByteBuffer, putbyteArray)
	{
		ByteBuffer* buf = ByteBuffer::allocate(1024);
		QByteArray bytes = QString("Test").toLocal8Bit();
		buf->put(&bytes);
		EXPECT_TRUE(buf->getPosition() == 4);
		buf->setPosition(0);
		QByteArray bytes2;
		buf->get(&bytes2);
		EXPECT_TRUE( memcmp(bytes.data(), bytes2.data(), bytes.size()) );
		delete buf;
	}

	// Tests that the endianess conversion is coorrect for 16 bits
	TEST_F(TestByteBuffer, endian16)
	{
		ByteBuffer* buf = ByteBuffer::allocate(1024);
		buf->setOrder(ByteOrder::BIG_ENDIAN_DATA);
		buf->putShort(0x3366);
		buf->setPosition(0);
		buf->setOrder(ByteOrder::LITTLE_ENDIAN_DATA);
		EXPECT_TRUE(buf->getInt() == 0x6633);
		delete buf;
	}

	// Tests that the endianess conversion is coorrect for 32 bits
	TEST_F(TestByteBuffer, endian32)
	{
		ByteBuffer* buf = ByteBuffer::allocate(1024);
		buf->setOrder(ByteOrder::BIG_ENDIAN_DATA);
		buf->putInt(0x77665544);
		buf->setPosition(0);
		buf->setOrder(ByteOrder::LITTLE_ENDIAN_DATA);
		EXPECT_TRUE(buf->getInt() == 0x44556677);
		delete buf;
	}

	// Tests that the endianess conversion is coorrect for 64 bits
	TEST_F(TestByteBuffer, endian64)
	{
		ByteBuffer* buf = ByteBuffer::allocate(1024);
		buf->setOrder(ByteOrder::BIG_ENDIAN_DATA);
		buf->putLong(0x1122334455667788);
		buf->setPosition(0);
		buf->setOrder(ByteOrder::LITTLE_ENDIAN_DATA);
		EXPECT_TRUE(buf->getLong() == (qint64)0x8877665544332211);
		delete buf;
	}
}
