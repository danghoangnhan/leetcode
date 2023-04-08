/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold = INT_MIN/2;
        int sold = 0;
        for (int i = 0; i < prices.size(); i++){
            int hold2 =  hold;
            int sold2 = sold;
            hold = max(hold,sold2-prices[i]) ;
            sold = max(sold2,hold2+prices[i]-fee);
        }        
        return sold;
    }
};
// @lc code=end

