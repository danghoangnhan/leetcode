/*
 * @lc app=leetcode id=2379 lang=cpp
 *
 * [2379] Minimum Recolors to Get K Consecutive Black Blocks
 */

// @lc code=start
#include "bits/stdc++.h"
class Solution {
public:
    int minimumRecolors(std::string blocks, int k) {
        int current_white = 0;
        int min_white;

        for (int i = 0; i < k; ++i) {
            if (blocks[i] == 'W') {
                ++current_white;
            }
        }
        min_white = current_white;

        for (int i = k; i < blocks.size(); ++i) {
            if (blocks[i - k] == 'W') {
                --current_white;
            }
            if (blocks[i] == 'W') {
                ++current_white;
            }
            min_white = min(min_white, current_white);
        }
        return min_white;
    }
};

// @lc code=end

