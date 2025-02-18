/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;

        if(target == 0) {
            result.push_back({});
            return result;
        }
        if(target < 0) {
            return result;
        }

        for(auto& candidate:candidates){
            if(candidate <= target) {
                vector<vector<int>> subResults = combinationSum(
                    candidates,
                    target - candidate);
                    
                for(auto& data : subResults) {
                    data.insert(data.begin(), candidate);
                    result.push_back(data);
                }
            }
        }
        return result;
    }
};
// @lc code=end

