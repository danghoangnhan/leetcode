#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        vector<int> canJump(nums.size(),INT_MAX);
        canJump[0]=0;
        for (int i = 0; i < nums.size()-1; i++){
            if(canJump[i]!=INT_MAX){
                for (int j = i+1; j <= nums[i]+i && j <nums.size(); j++){
                    canJump[j]=min(canJump[j],canJump[i]+1);
                }
            }
        }
        return canJump[nums.size()-1];
    }
};
// @lc code=end

