#include <vector>
#include <limits>
using namespace std;
/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        for (int i = 2; i < nums.size(); i++){
            int previous= INT_MIN;
            for (int j = 0; j <i -1; j++){
                previous = max(previous,nums[j]);
            }
            nums[i]=nums[i]+previous;
        }
        int result = nums[0];
        for(int i =1 ;i<nums.size();i++){
            result = max(result,nums[i]);
        }
        return result;
    }
};
// @lc code=end


