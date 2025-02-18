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
        int minBuy = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++){
                minBuy = min(prices[i],minBuy);
                profit = max(prices[i]-minBuy,profit);
        }        
        return profit;
    }
};
// @lc code=end

