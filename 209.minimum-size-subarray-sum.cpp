/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& v) {
        int left = 0 ;
        int n = v.size();
        int currentSum = 0 ;
        int minSize = INT_MAX; 
        for(int i = 0 ;i < n ; i++){  
            currentSum += v[i] ; 
            
            while(currentSum >= target){
                minSize = min(minSize, i - left + 1);
                currentSum -= v[left];
                left ++;
            }
        }
        return (minSize != INT_MAX) ? minSize : 0;
    }
};
// @lc code=end

