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
            int currentRob =0, previousRob =0;
            for (int num:nums){
                int newRob = max(previousRob+num,currentRob);
                previousRob = currentRob;
                currentRob = newRob;
            }
            return currentRob;
    }
};
// @lc code=end


