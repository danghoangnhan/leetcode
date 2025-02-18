#include <map>
#include <vector>
#include <math.h>
#include<climits>
using namespace std;

/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.empty()) {
            return 0;
        }
        
        int n = prices.size();
        
        // Initialize our DP vectors
        vector<int> buy(n, 0);
        vector<int> sell(n, 0);
        vector<int> cooldown(n, 0);
        
        // Set initial states
        buy[0] = -prices[0];  // We spend money to buy on day 0
        sell[0] = 0;  // We can't sell on day 0
        cooldown[0] = 0;  // We start with 0 profit
        
        for (int i = 1; i < n; i++) {
            // We can either buy on this day, or keep what we had yesterday
            buy[i] = max(buy[i-1], cooldown[i-1] - prices[i]);
            
            // If we're selling, it must be stock we bought before
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
            
            // Cooldown is the max profit we had yesterday
            cooldown[i] = max(cooldown[i-1], sell[i-1]);
        }
        // The maximum profit is the max of the last day's states
        return max(sell[n-1], cooldown[n-1]);
    }
};
// @lc code=end

