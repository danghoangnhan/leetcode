/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int result=0;
        int n=arr.size();
        stack<int> s;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<s.top()){
            
            }
            result+=s.top();
        }
        return result;
    }
};
// @lc code=end

