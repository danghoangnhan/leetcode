/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        //https://www.cnblogs.com/grandyang/p/6026066.html
        return (int)((-1 + sqrt(1 + 8 * (long)n)) / 2);
    }
};
// @lc code=end

