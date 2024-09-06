/*
 * @lc app=leetcode id=1460 lang=cpp
 *
 * [1460] Make Two Arrays Equal by Reversing Subarrays
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if (target.size() != arr.size()) {
            return false;
        }
        multiset<int> targetSet(target.begin(), target.end());
        multiset<int> arrSet(arr.begin(), arr.end());

        return targetSet == arrSet;

    return true;
    }
};
// @lc code=end

