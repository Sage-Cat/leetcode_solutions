// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>

using std::string;

// Solution
// Time Complexity O(n)
// Space Complexity O(min(n, m))

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        std::size_t result{0};

        std::unordered_map<char, std::size_t> charIndexMap;
        for (std::size_t start = 0, end = 0; end < s.size(); ++end)
        {
            if (charIndexMap.find(s[end]) != charIndexMap.end())
            {
                start = std::max(charIndexMap[s[end]] + 1, start);
            }

            charIndexMap[s[end]] = end;
            result = std::max(result, end - start + 1);
        }

        return result;
    }
};
