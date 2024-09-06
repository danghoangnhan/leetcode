/*
 * @lc app=leetcode id=2134 lang=cpp
 *
 * [2134] Minimum Swaps to Group All 1's Together II
 */

// @lc code=start
#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
     int minSwaps(vector<int>& nums) {
        
        int totalOnes = accumulate(nums.begin(), nums.end(), 0);
        
        if (totalOnes == 0 || totalOnes == nums.size()) {
            return 0;
        }

        int n = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());

        int maxOnesInWindow = 0;
        int currentOnesInWindow = 0;

        for (int i = 0; i < totalOnes; ++i) {
            if (nums[i] == 1) {
                ++currentOnesInWindow;
            }
        }

        maxOnesInWindow = currentOnesInWindow;

        // Slide the window over the extended array
        for (int i = totalOnes; i < n + totalOnes; ++i) {
            if (nums[i - totalOnes] == 1) {
                --currentOnesInWindow;
            }
            if (nums[i] == 1) {
                ++currentOnesInWindow;
            }
            maxOnesInWindow = max(maxOnesInWindow, currentOnesInWindow);
        }

        // Minimum swaps needed is the number of 0's in the best window
        return totalOnes - maxOnesInWindow;
    }
};
// @lc code=end

