#include <map>
#include <vector>
#include <math>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
public:
    map<int,int> frequency;
    int deleteAndEarn(vector<int>& nums) {
        vector<int>mapping;
        int result =-1;
        for (int num:nums){
            if (frequency.count(num)){
                frequency[num]++;
            }
            else{
                mapping.push_back(num);
                frequency[num]=1;
            }
        }
        sort(mapping.begin(), mapping.end());

        return rob(mapping);
    }
    int rob(vector<int>& nums) {
        int currentRob =0, previousRob =0;
        for (int i=0;i<nums.size();i++){
            int newRob = nums[i]*this->frequency[nums[i]];
            if (i>0 && nums[i] == nums[i-1]+1){
                int tmp = currentRob;
                currentRob = max(newRob + previousRob,currentRob);
                previousRob = tmp;
            }else{
                int tmp = currentRob;
                currentRob += newRob;
                previousRob = tmp;
            }
        }
        return currentRob;
    }
};
// @lc code=end

