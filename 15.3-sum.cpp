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
        vector<vector<int>> result;
        int n = nums.size();

        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if (i > 0 && nums[i] == nums[i]){
                continue;
            }
        }
        return result;
    }
};
// @lc code=end

