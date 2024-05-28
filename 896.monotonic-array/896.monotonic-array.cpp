#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
 */

// @lc code=start
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()<3)return true;
        int minValue = nums[0];
        int maxValue = nums[0];
        int minCheck=true;
        int maxCheck=true;
        
        for (int i = 0; i < nums.size(); i++){
            if(nums[i]<=minValue){
                minValue=nums[i];
            }
            else{
                minCheck=false;
            }
            if(nums[i]>=maxValue){
                maxValue=nums[i];
            }
            else{
                maxCheck=false;
            }
            if(!minCheck && !maxCheck) return false;
        }
        return true;
    }
};
// @lc code=end

