#include <gtest/gtest.h>

#include "ZigzagConversion.hpp"

class ZigzagConversionTest : public ::testing::Test
{
protected:
    Solution solution;
};

TEST_F(ZigzagConversionTest, BasicTest)
{
    EXPECT_EQ(solution.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
    EXPECT_EQ(solution.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
}

TEST_F(ZigzagConversionTest, SingleRowTest)
{
    EXPECT_EQ(solution.convert("PAYPALISHIRING", 1), "PAYPALISHIRING");
}

TEST_F(ZigzagConversionTest, SingleCharacterTest)
{
    EXPECT_EQ(solution.convert("A", 1), "A");
    EXPECT_EQ(solution.convert("B", 2), "B");
}

TEST_F(ZigzagConversionTest, TwoRowsTest)
{
    EXPECT_EQ(solution.convert("ABCD", 2), "ACBD");
}

TEST_F(ZigzagConversionTest, EdgeCaseTest)
{
    EXPECT_EQ(solution.convert("", 3), "");
    EXPECT_EQ(solution.convert("AB", 10), "AB");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}