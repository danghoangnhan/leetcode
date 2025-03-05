/*
 * @lc app=leetcode id=2570 lang=cpp
 *
 * [2570] Merge Two 2D Arrays by Summing Values
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> mergedMap;

        for (const auto& num : nums1) {
            mergedMap[num[0]] += num[1];
        }

        for (const auto& num : nums2) {
            mergedMap[num[0]] += num[1];
        }

        vector<vector<int>> result;
        result.reserve(mergedMap.size()); 

        for (const auto& [key, value] : mergedMap) {
            result.emplace_back(vector<int>{key, value});
        }

        return result;
    }
};

// @lc code=end

