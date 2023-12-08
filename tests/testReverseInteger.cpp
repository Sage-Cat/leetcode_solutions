#include <gtest/gtest.h>
#include "ReverseInteger.hpp"

class ReverseIntegerTest : public ::testing::Test
{
protected:
    Solution solution;
};

TEST_F(ReverseIntegerTest, TestPositiveNumber)
{
    EXPECT_EQ(solution.reverse(123), 321);
}

TEST_F(ReverseIntegerTest, TestNegativeNumber)
{
    EXPECT_EQ(solution.reverse(-123), -321);
}

TEST_F(ReverseIntegerTest, TestOverflow)
{
    EXPECT_EQ(solution.reverse(2147483647), 0);  // Max 32-bit integer
    EXPECT_EQ(solution.reverse(-2147483648), 0); // Min 32-bit integer
}

TEST_F(ReverseIntegerTest, TestZero)
{
    EXPECT_EQ(solution.reverse(0), 0);
}

TEST_F(ReverseIntegerTest, TestEndingWithZero)
{
    EXPECT_EQ(solution.reverse(120), 21);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
