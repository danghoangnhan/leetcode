#include<vector>
using namespace std;
/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long int> dp(target+2,0);
        for (long long int i = 1; i <= target; i++){
            for (int coin:nums){
                long long int remain = i - coin;
                if (remain<0){continue;}
                if (remain>=0){
                    dp[i] += 1+dp[remain];
                }
            }
        }
        for(int i=0;i<dp.size();i++){
            cout<<dp[i]<<" ";
        }
            
        return dp[target];
        
    }
};
// @lc code=end

