#include <gtest/gtest.h>

#include <random>
#include <string>
#include <unordered_set>

#include "LongestSubstr.hpp"

class LengthOfLongestSubstringTest : public ::testing::Test
{
protected:
    Solution solution;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;

    LengthOfLongestSubstringTest() : gen(rd()), dis(32, 126) {} // ASCII range

    // Generates a random string of given length
    std::string generateRandomString(size_t length)
    {
        std::string result;
        for (size_t i = 0; i < length; ++i)
        {
            char ch = static_cast<char>(dis(gen));
            result += ch;
        }
        return result;
    }

    // Brute force method to find longest substring without repeating characters
    int bruteForceLongestSubstring(const std::string &s)
    {
        int max_length = 0;
        for (size_t i = 0; i < s.length(); ++i)
        {
            std::unordered_set<char> char_set;
            for (size_t j = i; j < s.length(); ++j)
            {
                if (char_set.find(s[j]) != char_set.end())
                    break;
                char_set.insert(s[j]);
                max_length = std::max(max_length, static_cast<int>(j - i + 1));
            }
        }
        return max_length;
    }
};

// ------------------------ FIXED TESTS -----------------------------
// Test case for an empty string
TEST_F(LengthOfLongestSubstringTest, EmptyString)
{
    std::string input = "";
    int expected = 0;
    EXPECT_EQ(solution.lengthOfLongestSubstring(input), expected);
}

// Test case for a string with unique characters
TEST_F(LengthOfLongestSubstringTest, UniqueCharacters)
{
    std::string input = "abcdef";
    int expected = 6;
    EXPECT_EQ(solution.lengthOfLongestSubstring(input), expected);
}

// ------------------------ RANDOM TESTS -----------------------------
TEST_F(LengthOfLongestSubstringTest, RandomizedTest)
{
    for (int i = 0; i < 1000; ++i)
    {
        std::string randomString = generateRandomString(50); // Generate a string of length 50
        int expected = bruteForceLongestSubstring(randomString);
        int result = solution.lengthOfLongestSubstring(randomString);
        EXPECT_EQ(expected, result);
    }
}

// Main function
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
