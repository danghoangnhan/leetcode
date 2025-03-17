/*
 * @lc app=leetcode id=2206 lang=cpp
 *
 * [2206] Divide Array Into Equal Pairs
 */

// @lc code=start
#include "bits/stdc++.h"

class Solution {
public:
    bool divideArray(std::vector<int>& nums) {
        // Fixed-size array to count occurrences (since x is in [1, 500])
        int count[501] = {0};
        
        // Count each number's occurrence
        for (int num : nums) {
            count[num]++;
        }
        
        for (int i = 1; i <= 500; ++i) {
            if (count[i] % 2 != 0) {
                return false;
            }
        }
        
        return true;
    }
};
// @lc code=end

