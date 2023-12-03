// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <vector>

using std::vector;

// Solution
// Time Complexity O(m+n)
// Space Complexity O(m+n)

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> merged(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());

        const size_t n = merged.size();
        double result{0.0};
        if (n % 2 == 0)
            result = (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        else
            result = merged[n / 2];

        return result;
    }
};