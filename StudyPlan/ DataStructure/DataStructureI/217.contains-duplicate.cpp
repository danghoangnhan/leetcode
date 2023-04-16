#include <set>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> visited;
        for(int element:nums){
            if(visited.count(element)){
                return true;
            }
            visited.insert(element);
        }
        return false;
    }
};
// @lc code=end

