#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1,vector<int>(coins.size(),0));
        for (int coin_index = 0; coin_index <  coins.size(); coin_index++){    dp[0][coin_index]=1;}

        for (int amount_index = 1; amount_index < dp.size(); amount_index++){
            for (int coin_index = 0; coin_index < coins.size(); coin_index++){
                if (coin_index>0){dp[amount_index][coin_index] += dp[amount_index][coin_index-1];}
                int remainder = amount_index - coins[coin_index];
                if (remainder>=0){
                    dp[amount_index][coin_index]+= dp[remainder][coin_index];
                }
            }
        }
        return dp[amount][coins.size()-1];
    }
};
// @lc code=end

