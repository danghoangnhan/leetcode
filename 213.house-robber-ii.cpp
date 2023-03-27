#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
        int robRange(vector<int>& nums,int start,int end) {
            int currentRob =0, previousRob =0;
            for (int i = start;i<end;i++){
                int newRob = max(previousRob+nums[i],currentRob);
                previousRob = currentRob;
                currentRob = newRob;
            }
            return currentRob;
    }
    int rob(vector<int>& nums) {
        if(nums.size()<=1)return nums[0];
        int result = max(robRange(nums,1,nums.size()),robRange(nums,0,nums.size()-1));
        return result;
    }
};
// @lc code=end

