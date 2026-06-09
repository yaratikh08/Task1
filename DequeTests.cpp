#include <gtest/gtest.h>
#include "Deque.h"

TEST(DequeTest, DefaultConstructor)
{
    Deque deque;
    EXPECT_TRUE(deque.empty());
    EXPECT_EQ(deque.getSize(), 0);
}

TEST(DequeTest, InitializerList)
{
    Deque deque{ 1, 2, 3 };
    EXPECT_EQ(deque.getSize(), 3);
    EXPECT_EQ(deque.front(), 1);
    EXPECT_EQ(deque.back(), 3);
}

TEST(DequeTest, PushBack)
{
    Deque deque;
    deque.push_back(10);
    deque.push_back(20);
    EXPECT_EQ(deque.getSize(), 2);
    EXPECT_EQ(deque.back(), 20);
}

TEST(DequeTest, PushFront)
{
    Deque deque;
    deque.push_front(10);
    deque.push_front(20);
    EXPECT_EQ(deque.getSize(), 2);
    EXPECT_EQ(deque.front(), 20);
}

TEST(DequeTest, PopBack)
{
    Deque deque{ 1, 2, 3 };
    deque.pop_back();
    EXPECT_EQ(deque.back(), 2);
    EXPECT_EQ(deque.getSize(), 2);
}

TEST(DequeTest, PopFront)
{
    Deque deque{ 1, 2, 3 };
    deque.pop_front();
    EXPECT_EQ(deque.front(), 2);
    EXPECT_EQ(deque.getSize(), 2);
}

TEST(DequeTest, EmptyAfterPops)
{
    Deque deque{ 1 };
    deque.pop_front();
    EXPECT_TRUE(deque.empty());
}

TEST(DequeTest, PopBackThrowsOnEmpty)
{
    Deque deque;
    EXPECT_THROW(deque.pop_back(), std::out_of_range);
}

TEST(DequeTest, PopFrontThrowsOnEmpty)
{
    Deque deque;
    EXPECT_THROW(deque.pop_front(), std::out_of_range);
}

TEST(DequeTest, ToString)
{
    Deque deque{ 1, 2, 3 };
    EXPECT_EQ(deque.toString(), "1 2 3");
}

TEST(DequeTest, CopyConstructor)
{
    Deque original{ 1, 2, 3 };
    Deque copy = original;
    EXPECT_EQ(copy.toString(), original.toString());
}

TEST(DequeTest, AssignmentOperator)
{
    Deque a{ 1, 2, 3 };
    Deque b;
    b = a;
    EXPECT_EQ(b.toString(), "1 2 3");
}

TEST(DequeTest, ShiftRightOperator)
{
    Deque deque{ 1, 2 };
    deque >> 3;
    EXPECT_EQ(deque.back(), 3);
}

TEST(DequeTest, ShiftLeftOperator)
{
    Deque deque{ 10, 20, 30 };
    int val = 0;
    deque << val;
    EXPECT_EQ(val, 10);
    EXPECT_EQ(deque.front(), 20);
}