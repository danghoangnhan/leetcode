#include <map>
using namespace std;
/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result  = 0;
        int currentSum =0;
        map<int,int> checking;
        checking[0]=1;
        for (int i = 0; i < nums.size(); i++)
        {
            currentSum += nums[i];
            if (checking.count(currentSum-k))
            {
                result += checking[currentSum-k];
            }
            checking[currentSum]++;
        }
        return result;        
    }
};
// @lc code=end

