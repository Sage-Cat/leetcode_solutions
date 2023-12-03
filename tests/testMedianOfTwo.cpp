#include <gtest/gtest.h>

#include <vector>

#include "MedianOfTwo.hpp"

using namespace std;

class MedianOfTwoTest : public ::testing::Test
{
protected:
    Solution solution;
};

TEST_F(MedianOfTwoTest, HandlesNonEmptyArrays)
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    EXPECT_DOUBLE_EQ(solution.findMedianSortedArrays(nums1, nums2), 2.0);

    nums1 = {1, 2};
    nums2 = {3, 4};
    EXPECT_DOUBLE_EQ(solution.findMedianSortedArrays(nums1, nums2), 2.5);
}

TEST_F(MedianOfTwoTest, HandlesOneEmptyArray)
{
    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    EXPECT_DOUBLE_EQ(solution.findMedianSortedArrays(nums1, nums2), 1.0);
}

TEST_F(MedianOfTwoTest, HandlesBothEmptyArrays)
{
    vector<int> nums1 = {};
    vector<int> nums2 = {};
    EXPECT_DOUBLE_EQ(solution.findMedianSortedArrays(nums1, nums2), 0.0);
}

TEST_F(MedianOfTwoTest, HandlesExtremeValues)
{
    vector<int> nums1 = {INT_MIN, INT_MIN};
    vector<int> nums2 = {INT_MAX, INT_MAX};
    EXPECT_DOUBLE_EQ(solution.findMedianSortedArrays(nums1, nums2), 0.5);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
