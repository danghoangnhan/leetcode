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
        int sold=0,rest=0,hold=INT_MIN;
        for(const int price:prices){
            int prev_sold = sold;
            sold = hold + price;
            hold = max(hold,rest - price);
            rest = max(rest,prev_sold);
        }
        return max(rest,sold);
    }
};
// @lc code=end

