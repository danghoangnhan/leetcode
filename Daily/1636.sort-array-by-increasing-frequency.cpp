/*
 * @lc app=leetcode id=1636 lang=cpp
 *
 * [1636] Sort Array by Increasing Frequency
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> frequency;
        for (auto num : nums) {
            frequency[num]++;
        }

        sort(nums.begin(), nums.end(), [&frequency](int a, int b) {
            if (frequency[a] != frequency[b]) {
                return frequency[a] < frequency[b];
            }
            return a > b;
        });
        return nums;
    }
};
// @lc code=end

