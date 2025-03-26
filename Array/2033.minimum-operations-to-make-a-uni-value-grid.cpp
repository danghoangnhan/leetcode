/*
 * @lc app=leetcode id=2033 lang=cpp
 *
 * [2033] Minimum Operations to Make a Uni-Value Grid
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> nums;
    
            for (auto& row : grid) {
                for (int num : row) {
                    nums.push_back(num);
                }
            }
    
            int base_mod = nums[0] % x;
            for (int num : nums) {
                if (num % x != base_mod) {
                    return -1; // 無法轉成相同數值
                }
            }
    
            for (int& num : nums) {
                num = (num - base_mod) / x; // 減掉餘數以後變成同一 base
            }
            sort(nums.begin(), nums.end());
    
            int median = nums[nums.size() / 2];
            int operations = 0;
            for (int num : nums) {
                operations += abs(num - median);
            }
    
            return operations;
        }
    };    
// @lc code=end

