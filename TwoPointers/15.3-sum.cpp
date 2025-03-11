/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        for (int i = 0; i < n - 2; ++i) {

            if (nums[i] > 0) break;
            
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                long long total = nums[i] + nums[left] + nums[right];
                
                if (total < 0) {
                    left++;
                } else if (total > 0) {
                    right--;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    left++;
                    while (left < right && nums[left] == nums[left - 1]) 
                        left++;             
                    right--;
                    while (left < right && nums[right] == nums[right + 1]) 
                        right--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

