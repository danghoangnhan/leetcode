#include <vector>
#include <iostream>
#include <climits>
using namespace std;
/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++){
            nums[i] = max(nums[i],nums[i-1]+nums[i]);
        }
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            result = max(nums[i],result);
        }
        return result;
    }
};
// @lc code=end

