/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
    while (low <= high) {
        int mid = int((low + high) / 2);
        if (target == nums[mid])
            return mid;
        else if (target > nums[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low ;
    }
};
// @lc code=end

