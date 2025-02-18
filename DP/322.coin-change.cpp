#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long int> dp(amount+2,amount +1);
        dp[0]=0;
        for (long long int i = 1; i <= amount; i++){
            for (int coin:coins){
                long long int remain = i - coin;
                if (remain<0){continue;}
                if (remain>=0){
                    dp[i] = min(dp[i],1+dp[remain]);
                }
            }
        }
        return (dp[amount]!=amount +1)?dp[amount]:-1;
    }
};
// @lc code=end

