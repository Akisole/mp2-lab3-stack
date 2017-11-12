
#include "..\mp2-lab3-stack\Stack.h"

#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> TS(3));
}

TEST(TStack, throws_when_create_steck_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> TS(-3));
}

TEST(TStack, create_steck_is_empty)
{
	TStack<int> TS(3);
	ASSERT_ANY_THROW(TS.Top());
	EXPECT_EQ(1, TS.IsEmpty());
}

TEST(TStack, can_assign_stack_of_equal_size)
{
	const int size=3;
	TStack<int> TS1(size), TS2(size);
	for(int i=1; i<=size; i++)
		TS1.Push(i);

	TS2=TS1;

	EXPECT_EQ(TS1.Top(), TS2.Top());

}

TEST(TStack, can_assign_stack_of_non_equal_size)
{
	const int size=3;
	TStack<int> TS1(size), TS2(size-1);
	for(int i=1; i<=size; i++)
		TS1.Push(i);

	TS2=TS1;

	EXPECT_EQ(TS1.Top(), TS2.Top());
	EXPECT_EQ(3, TS2.Top());

}

TEST(TStack, can_check_for_overflow)
{
	const int size=3;
	TStack<int> TS1(size);
	for(int i=1; i<=size-1; i++)
		TS1.Push(i);

	EXPECT_EQ(0, TS1.IsFull());
	TS1.Push(1);
	EXPECT_EQ(1, TS1.IsFull());
}

TEST(TStack, can_check_for_emptiness)
{
	TStack<int> TS1(3);
	TS1.Push(1);

	EXPECT_EQ(0, TS1.IsEmpty());
	TS1.Clear();
	EXPECT_EQ(1, TS1.IsEmpty());
}

TEST(TStack, can_watch_top_elem)
{
	TStack<int> TS1(3);
	TS1.Push(1);

	EXPECT_EQ(1, TS1.Top());
}

TEST(TStack, throw_when_watch_top_elem_from_empty_stack)
{
	TStack<int> TS1(3);

	ASSERT_ANY_THROW(TS1.Top());
}

TEST(TStack, can_pop_elem)
{
	const int size=3;
	TStack<int> TS1(size);
	for(int i=1; i<=size; i++)
		TS1.Push(i);

	int Top1=TS1.Top();
	int Top2=TS1.Pop();

	EXPECT_NE(TS1.Top(), Top1);
	EXPECT_EQ(Top1, Top2);
}

TEST(TStack, throw_when_pop_elem_from_empty_stack)
{
	TStack<int> TS1(3);

	ASSERT_ANY_THROW(TS1.Pop());
}

TEST(TStack, can_put_elem_in_stack)
{
	const int size=3;
	TStack<int> TS1(size);

	TS1.Push(1);

	EXPECT_EQ(1, TS1.Top());
}

TEST(TStack, throw_when_put_elem_in_full_stack)
{
	const int size=3;
	TStack<int> TS1(size);
	for(int i=1; i<=size; i++)
		TS1.Push(i);

	ASSERT_ANY_THROW(TS1.Push(1));
}

TEST(TStack, can_clear_stack)
{
	const int size=3;
	TStack<int> TS1(size);
	for(int i=1; i<=size; i++)
		TS1.Push(i);

	EXPECT_EQ(0, TS1.IsEmpty());
	TS1.Clear();

	EXPECT_EQ(1, TS1.IsEmpty());
	ASSERT_ANY_THROW(TS1.Top());
}












