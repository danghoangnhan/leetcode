/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int mid;
        while (hi >= lo) {
            mid = (hi + lo) / 2;
            
            if (nums[mid] == target)return mid;

            if (nums[mid] >= nums[lo]) {
                if (target > nums[mid]  || target <nums[lo]){
                    lo = mid +1;
                }else{
                    hi = mid -1;
                }
            }
            else{
                if (target < nums[mid]  || target >nums[hi]){
                    hi = mid - 1;
                }else{
                    lo = mid + 1;
                }
            } 
        }
        return -1;
    }   
};
// @lc code=end

