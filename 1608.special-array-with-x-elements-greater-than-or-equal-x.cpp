#include <vector>
#include <algorithm>
#include <set>
using namespace std;
/*
 * @lc app=leetcode id=1608 lang=cpp
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 */

// @lc code=start
class Solution {
public:
    int specialArray(vector<int>& nums) {
    vector<int> p(nums.size(),0);
    
    for (int i=0; i<nums.size(); i++){
        if (nums[i]>nums.size())
            p[nums.size()-1]++;
        else if (nums[i]!=0)
            p[nums[i]-1]++;
    }
    
    int sum = 0;
    for (int i=nums.size()-1; i>=0; i--){
        sum+=p[i];
        if (sum==i+1) return i+1;
    }
    return -1;
    }
};
// @lc code=end

