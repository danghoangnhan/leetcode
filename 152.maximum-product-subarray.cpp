#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++){
            nums[i] = max(nums[i],nums[i-1]*nums[i]);
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

