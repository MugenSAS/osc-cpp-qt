#include <osc/OscPatternMatching.h>
#include <gtest/gtest.h>
#include <QString>

namespace
	{

	class TestOscPatternMatching : public ::testing::Test {
	protected:
		TestOscPatternMatching()
		{
		}
		virtual ~TestOscPatternMatching()
		{
		}


		static int match(const char * address, const char * pattern, int addr_offset)
		{
			int pattern_offset;
			int address_offset;
			int ret = OSCPatternMatching::osc_match(address + addr_offset, pattern, &pattern_offset, &address_offset);
			char * next = (char *) (address + addr_offset + pattern_offset);
			if (ret==3){
				return pattern_offset;
			} else if (pattern_offset > 0 && *next == '/'){
				return pattern_offset;
			} else {
				return 0;
			}
		}

		static bool fullMatch( const char * address, const char * pattern, int addr_offset)
		{
			int pattern_offset;
			int address_offset;
			int ret = OSCPatternMatching::osc_match(address + addr_offset, pattern, &address_offset, &pattern_offset);
			return (ret==3);
		}
	};

	TEST_F(TestOscPatternMatching, checkHeavyPattern)
	{
		QString msg0("/{input,output}/[0-2]/[!ab]/*");
		int i = TestOscPatternMatching::match( msg0.toLocal8Bit().constData(), "/input/1", 0 );
		//match will traverse as far as it can in the pattern
		//it returns the number of characters matched from the pattern
		EXPECT_TRUE( i > 0 );
		//string multiple 'match' methods together using the pattern offset parameter to continue matching where it left off
		//use 'fullMatch' to test if the entire pattern was matched.
		bool b = TestOscPatternMatching::fullMatch( msg0.toLocal8Bit().constData(), "/c/anything", i );
		EXPECT_TRUE( b );
	}

	TEST_F(TestOscPatternMatching, checkPartialPattern)
	{
		QString msg0("/partialMatch");
		int i = TestOscPatternMatching::match( msg0.toLocal8Bit().constData(), "/partial", 0 );
		//match will return 0 if it did not reach the end or a '/'
		EXPECT_TRUE( i == 0 );
	}
}
