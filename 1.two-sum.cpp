#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> maps;
        vector<int> result;
        for (int index = 0; index < nums.size(); index++){
            if (maps.count(nums[index]))
            {
                result.push_back(maps[nums[index]]);
                result.push_back(index);
                break;
            }
            else{
                maps[target - nums[index]] = index;
            }
        }
        return result;
    }
};
// @lc code=end

