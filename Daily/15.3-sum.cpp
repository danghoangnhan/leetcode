/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];

                if (total > 0) {
                    left--;
                } else if (total < 0) {
                    right++;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while (nums[left] == nums[left-1] && left < right) {
                        left++;
                    }
                }
            }
        }
        return res;        
    }
};
// @lc code=end

