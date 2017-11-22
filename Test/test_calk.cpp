
#include "..\mp2-lab3-stack\Calk.h"

#include "gtest.h"

TEST(TCalk, can_calculate_with_priority)
{
	string inf="4+3*2";
	TCalk Calk(inf);

	int res=Calk.CCalk();
	EXPECT_EQ(10, res);
}

TEST(TCalk, can_create_tcalk_with_string)
{
	string inf="*";
	ASSERT_NO_THROW(TCalk(inf));
}

TEST(TCalk, can_create_postfix)
{

	//
}