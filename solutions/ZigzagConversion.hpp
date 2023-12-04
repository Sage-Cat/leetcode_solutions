// https://leetcode.com/problems/zigzag-conversion/

#include <vector>
#include <string>

using std::min;
using std::string;
using std::vector;

// Solution
// Time Complexity O(n)
// Space Complexity O(n)

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.length())
            return s;

        vector<string> rows(min(numRows, int(s.length())));
        for (auto &row : rows) // optimization by reserving space
            row.reserve(s.length() / numRows + 1);

        int currentRow = 0;
        bool goingDown = false;

        // Iterate over each character in the string
        for (char c : s)
        {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1)
                goingDown = !goingDown; // Change direction

            currentRow += goingDown ? 1 : -1; // Move up or down
        }

        string result{};
        result.reserve(s.length());
        for (const auto &row : rows)
            result += row;

        return result;
    }
};