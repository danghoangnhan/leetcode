#include<vector>
#include<math.h>
using namespace std;
/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = rangSumArray(nums);
        int maxSub = maxSubArray(nums);
        int minSub = minSubArray(nums); 
        if (sum - minSub == 0){
            return maxSub;
        }else{
            return max(maxSub,sum - minSub);
        }
    }
    int maxSubArray(vector<int>& nums) {
        int localMax=0;
        int globalMax =nums[0];
        for (int element:nums){
            localMax= max(element,localMax+element);
            globalMax = max(localMax,globalMax);
        }
        return globalMax;
    }
        int minSubArray(vector<int>& nums) {
        int localMin=0;
        int globalMin =nums[0];
        for (int element:nums){
            localMin= min(element,localMin+element);
            globalMin = min(localMin,globalMin);
        }
        return globalMin;
    }
    int rangSumArray(vector<int>& nums) {
        int result =0;
        for (int element:nums){
            result += element;
        }
        return result;
    }
};
// @lc code=end

