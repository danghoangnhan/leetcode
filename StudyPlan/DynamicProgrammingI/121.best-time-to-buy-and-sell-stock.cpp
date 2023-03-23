#include<vector>
using namespace std;
/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> minBuy(prices.size(),10001);
        vector<int> profit(prices.size(),0);
        minBuy[0] = prices[0];

        for (int i = 1; i < profit.size(); i++){
                minBuy[i] = min(prices[i],minBuy[i-1]);
                profit[i] = max(prices[i]-minBuy[i],profit[i-1]);
        }        
        return profit[prices.size()-1];
    }
};
// @lc code=end

