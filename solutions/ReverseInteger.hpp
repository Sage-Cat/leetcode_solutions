// https://leetcode.com/problems/reverse-integer/

#include <limits>

// Solution
class Solution
{
public:
    int reverse(int x)
    {
        int reversed{};
        while (x != 0)
        {
            const int digit = x % 10;
            x /= 10;

            // Check for overflow/underflow
            if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7))
                return 0;
            if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8))
                return 0;

            reversed = reversed * 10 + digit;
        }
        return reversed;
    }
};