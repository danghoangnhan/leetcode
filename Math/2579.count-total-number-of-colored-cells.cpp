/*
 * @lc app=leetcode id=2579 lang=cpp
 *
 * [2579] Count Total Number of Colored Cells
 */

// @lc code=start
class Solution {
public:
    long long coloredCells(int n) {
        return 2LL * n * n - 2LL * n + 1;
    }
};
// @lc code=end

