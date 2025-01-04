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
        for(auto& candidate:candidates){
            if(candidate>target){
                vector<vector<int>> datas = combinationSum(
                    candidates,
                    target-candidate);
                for(auto& data:datas){
                    data.push_front(candidate);
                    result.push_back(data);
                }
            }
        }
        return result;
    }
};
// @lc code=end

