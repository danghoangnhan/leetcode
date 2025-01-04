/*
 * @lc app=leetcode id=2270 lang=cpp
 *
 * [2270] Number of Ways to Split Array
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long int>preFix(nums.size(),0);
        int result = 0;
        int length = nums.size();
        preFix[0] = nums[0];
        
        for(int i=1;i<nums.size();i++){
            preFix[i]=nums[i]+preFix[i-1];
        }
        for(int i=0;i<length-1;i++){
            if(preFix[i]>=preFix[length-1]-preFix[i]){
                result++;
            }
        }
        return result;
    }
};
// @lc code=end

