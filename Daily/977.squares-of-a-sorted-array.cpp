/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left =0,right=n-1,i=n-1;
        vector<int> result(n,0);
        while(left<=right){
            if(abs(nums[left]) < abs(nums[right])){
                result[i--] = nums[left] * nums[left]; 
                left++;
            }
            else {
                result[i--] = nums[right] * nums[right]; 
                right--;
            }
        }
        result[0] = nums[i] * nums[i]; 
        return result;
    }
};
// @lc code=end

