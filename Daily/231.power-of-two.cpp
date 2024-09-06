/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        for (int  i = 0; i < 31; i++)
            if (1<<i==n)return true;
        return false;
    }
};
// @lc code=end