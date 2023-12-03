
// https://leetcode.com/problems/longest-palindromic-substring/

#include <string>
#include <algorithm>
#include <unordered_map>

using std::size_t;
using std::string;
using std::unordered_map;

// Solution
// Time Complexity O(n^2)
// Space Complexity O(1)

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";

        int start = 0, maxLength = 1;
        for (int i = 0; i < s.length(); ++i)
        {
            expandAroundCenter(s, i, i, start, maxLength);     // Odd length palindromes
            expandAroundCenter(s, i, i + 1, start, maxLength); // Even length palindromes
        }

        return s.substr(start, maxLength);
    }

private:
    void expandAroundCenter(const string &s, int left, int right, int &start, int &maxLength)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            --left;
            ++right;
        }

        int currentLength = right - left - 1;
        if (currentLength > maxLength)
        {
            start = left + 1;
            maxLength = currentLength;
        }
    }
};