#include<vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        vector<bool> canJump(nums.size(),false);
        canJump[0]=true;
        for (int i = 0; i < nums.size()-1; i++){
            if(canJump[i]==true){
                for (int j = i+1; j <= nums[i]+i && j <nums.size(); j++){
                    canJump[j]=true;
                    if (j == nums.size()-1){
                        return true;
                    }
                    
                }
            }
        }
        return canJump[nums.size()-1];
    }
};
// @lc code=end

