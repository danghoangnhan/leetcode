#include <vector>
#include <map>
using namespace std;
/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>check;
        int majourity = nums.size()/2;
        int result = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (check.count(nums[i])){
                check[nums[i]]++;
            }
            else{
                check[i]=1;
            }
            if (check[nums[i]]>=majourity){
                result =  nums[i];
            }
        }
        return result;
    }
};
// @lc code=end

