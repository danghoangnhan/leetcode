/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int left = 0, right = 1;
        int size = nums.size();
        vector<string> result;

        while (left < size) {
            while (right < size && (long long)(nums[right]) - (long long)(nums[right - 1]) == 1) {
                right++;
            }
            if (right - left > 1) {
                result.push_back(
                    to_string(nums[left]) + "->" + 
                    to_string(nums[right - 1]));
            } else {
                result.push_back(to_string(nums[left]));
            }
            left = right++;
        }
        return result;
    }
};
// @lc code=end

