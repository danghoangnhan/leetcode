#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size()==1){
            result.push_back(nums);
            return result;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int number = nums[i];
            vector<int> other = nums;
            other.erase(other.begin() + i);
            vector<vector<int>> backs = permute(other);
            for(vector<int>back:backs){
                back.insert(back.begin(),number);
                result.push_back(back);
            }
        }
        return result;
    }
};
// @lc code=end

