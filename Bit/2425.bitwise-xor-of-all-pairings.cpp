/*
 * @lc app=leetcode id=2425 lang=cpp
 *
 * [2425] Bitwise XOR of All Pairings
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        
        if (nums1.size() & 1) {
            for (int num : nums2) {
                result ^= num;
            }
        }
        
        if (nums2.size() & 1) {
            for (int num : nums1) {
                result ^= num;
            }
        }
        
        return result;
    }
};
// @lc code=end

