/*
 * @lc app=leetcode id=2582 lang=cpp
 *
 * [2582] Pass the Pillow
 */

// @lc code=start
class Solution {
public:
    int passThePillow(int n, int time) {
        int step = time % (n - 1);
        return ((time / (n - 1)) % 2 == 0?step + 1: n - step);
    }
};
// @lc code=end

