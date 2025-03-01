/*
 * @lc app=leetcode id=2460 lang=cpp
 *
 * [2460] Apply Operations to an Array
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int size = nums.size();
        for(int i=0;i<size-1;i++){
            if(nums[i] && nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        int pos = 0;
        for(int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[pos]);
                pos++;
            }
        }
        return nums;
    }
};
// @lc code=end

