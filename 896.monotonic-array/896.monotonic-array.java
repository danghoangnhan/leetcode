
/*
 * @lc app=leetcode id=896 lang=java
 *
 * [896] Monotonic Array
 */

// @lc code=start
class Solution {
    public boolean isMonotonic(int[] nums) {
        if (nums.length < 3) {
            return true;
        }
        
        int minValue = nums[0];
        int maxValue = nums[0];
        boolean minCheck = true;
        boolean maxCheck = true;
        
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] <= minValue) {
                minValue = nums[i];
            } else {
                minCheck = false;
            }
            
            if (nums[i] >= maxValue) {
                maxValue = nums[i];
            } else {
                maxCheck = false;
            }
            
            if (!minCheck && !maxCheck) {
                return false;
            }
        }
        
        return true;
    }
}

// @lc code=end