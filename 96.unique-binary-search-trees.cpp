/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        int result = 1;
        for (int i = 2; i <= n; i++){
            result  = result+2;
        }
        return result;
    }
};
// @lc code=end

