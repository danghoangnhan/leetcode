#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        int result = dp[nums.size()-1];
        for (int i = nums.size()-1; i >=0 ; i--){
            for (int j = i+1; j < nums.size(); j++){
                if (nums[i]<nums[j]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
            result = max(result,dp[i]);
        }
        return result;
    }
};
// @lc code=end

