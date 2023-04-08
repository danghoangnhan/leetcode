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
        
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++){
            int mul = nums[0];
            for (int j = 0; j < i; j++){
                result = max(nums[j]*mul,result);
                mul *= nums[j];
            }
            }
            result = max(mul,result);
        }
        

        return result;
    }
};
// @lc code=end

