#include <map>
#include<set>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> frequency;
        vector<int> result;
        for (auto num:nums1){
            if (frequency.count(num)){
                frequency[num]++;
            }else{
                frequency.emplace(num,1);
            }
        }
        for (auto num:nums2){
            if (frequency.count(num)&& frequency[num]>0){
                result.push_back(num);
                frequency[num]--;
            }
        }
        return result;
    }
};
// @lc code=end

