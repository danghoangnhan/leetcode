#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int>positive(nums.size(),1);
        vector<int>negative(nums.size(),1);
        for (int i = 0 ;i <nums.size(); i++){
            for (int j = 0; j < i; j++){
                if (nums[i]>nums[j]){
                    positive[i] = max(positive[i],1+negative[j]);
                }
                if (nums[i]<nums[j]){
                    negative[i] = max(negative[i],1+positive[j]);
                }
            }
        }
        return max(positive[nums.size()-1],negative[nums.size()-1]);
    }
};
// @lc code=end

