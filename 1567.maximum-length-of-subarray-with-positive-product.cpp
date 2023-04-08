/*
 * @lc app=leetcode id=1567 lang=cpp
 *
 * [1567] Maximum Length of Subarray With Positive Product
 */

// @lc code=start
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int currentMax=1,currentMin=1;
        int result = 1;
        for(auto num:nums){
            if (num==0){
                currentMax=1;
                currentMin=1;
                result = max(result,1);
                continue;
            }
            int tmp = currentMax *num;
            currentMax = max(num*currentMax,max(num*currentMin,num));
            currentMin = min(tmp,min(num*currentMin,num));
            result = max(result,currentMax);
        }
        return result;
    }
};
// @lc code=end

