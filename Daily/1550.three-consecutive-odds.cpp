/*
 * @lc app=leetcode id=1550 lang=cpp
 *
 * [1550] Three Consecutive Odds
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for (int num : arr) {
            if (num % 2 != 0) {
                count++;
                if (count == 3) return true;
            } else {
                count = 0;
            }
        }
        return false;
    }
};
};
// @lc code=end

