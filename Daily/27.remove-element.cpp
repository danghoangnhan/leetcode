/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            if (nums[i] == val) {
                swap(nums[i], nums[n - 1]);
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
};

// @lc code=end

