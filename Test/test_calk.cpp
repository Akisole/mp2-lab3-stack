
#include "..\mp2-lab3-stack\Calk.h"

#include "gtest.h"

TEST(TCalk, can_calculate_with_priority)
{
	string inf="2*4+3*(2-(5+3))";
	TCalk Calk(inf);

	int res=Calk.CCalk();
	EXPECT_EQ(-10, res);
}

TEST(TCalk, can_create_tcalk_with_string)
{
	string inf="*";
	ASSERT_NO_THROW(TCalk(inf));
}

TEST(TCalk, can_create_tcalk)
{
	ASSERT_NO_THROW(TCalk("2+6"));
}

TEST(TCalk, cheek_can_cheeking)
{
	TCalk Calk1("(4+3"); 
	TCalk Calk2("4+3)"); 
	TCalk Calk3("(4+3)");

	EXPECT_EQ(0, Calk1.Cheek());
	EXPECT_EQ(0, Calk2.Cheek());
	EXPECT_EQ(1, Calk3.Cheek());
}

TEST(TCalk, throw_when_calculate_with_letters)
{
	string inf="4+j3*2";
	TCalk Calk(inf);

	ASSERT_ANY_THROW(Calk.CCalk());
}

TEST(TCalk, throw_when_calculate_with_much_operations)
{
	string inf="*4+3";
	TCalk Calk(inf);

	ASSERT_ANY_THROW(Calk.CCalk());
}

TEST(TCalk, throw_when_calculate_with_much_skobok)
{
	string inf="(4+3";
	TCalk Calk(inf);

	ASSERT_ANY_THROW(Calk.CCalk());
}