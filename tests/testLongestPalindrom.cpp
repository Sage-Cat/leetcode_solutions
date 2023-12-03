#include <gtest/gtest.h>

#include "LongestPalindrom.hpp"

class LongestPalindromeTest : public ::testing::Test
{
protected:
    Solution solution;
};

// Test basic cases
TEST_F(LongestPalindromeTest, BasicCases)
{
    EXPECT_EQ(solution.longestPalindrome("babad"), "bab"); // "aba" is also a valid answer
    EXPECT_EQ(solution.longestPalindrome("cbbd"), "bb");
}

// Test edge cases
TEST_F(LongestPalindromeTest, EdgeCases)
{
    EXPECT_EQ(solution.longestPalindrome(""), "");
    EXPECT_EQ(solution.longestPalindrome("a"), "a");
    EXPECT_EQ(solution.longestPalindrome("aa"), "aa");
}

// Test cases with longer strings
TEST_F(LongestPalindromeTest, LongerStrings)
{
    EXPECT_EQ(solution.longestPalindrome("racecar"), "racecar");
    EXPECT_EQ(solution.longestPalindrome("tracecars"), "racecar");
}

// Test cases with no palindromes
TEST_F(LongestPalindromeTest, NoPalindrome)
{
    EXPECT_EQ(solution.longestPalindrome("abc"), "a");  // or "b", or "c"
    EXPECT_EQ(solution.longestPalindrome("abcd"), "a"); // or any single character
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
