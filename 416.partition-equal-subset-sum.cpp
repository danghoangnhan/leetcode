/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        
        for (int num : nums) total_sum += num;

        if (total_sum % 2 != 0) return false;

        int target = total_sum / 2;
        int n = nums.size();

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[target];
    }
};
// @lc code=end

