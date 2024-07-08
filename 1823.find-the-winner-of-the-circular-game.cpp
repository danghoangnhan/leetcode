/*
 * @lc app=leetcode id=1823 lang=cpp
 *
 * [1823] Find the Winner of the Circular Game
 */

// @lc code=start
class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0;

        for (int i = 1; i <= n; ++i) {
            winner = (winner + k) % i;
        }
            
    return winner + 1;
    }
};
// @lc code=end

