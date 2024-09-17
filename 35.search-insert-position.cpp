/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i;
        for(i =0 ;i<nums.size();i++){
            if(nums[i]>=target){
                break;
            }
        }
        return i;
    }
};
// @lc code=end

