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
        
        for (int i = 0; i < nums.size(); i++){
            int mul = nums[i];
            for (int j = i +1; j < nums.size(); j++){
                result  = max(result,mul);
                mul *= nums[j];
            }
            result = max(mul,result);
        }
        

        return result;
    }
};
// @lc code=end

