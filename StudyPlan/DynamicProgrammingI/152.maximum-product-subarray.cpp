#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentMax=1,currentMin=1;
        int result = nums[0];
        for(auto num:nums){
            if (num==0){
                currentMax=1;
                currentMin=1;
                result = max(result,num);
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

