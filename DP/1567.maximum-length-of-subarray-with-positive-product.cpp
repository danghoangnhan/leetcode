#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=1567 lang=cpp
 *
 * [1567] Maximum Length of Subarray With Positive Product
 */

// @lc code=start
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int positiveLength=0,negativeLength=0,result = 0;
        for(auto num:nums){
            if (num==0){
                positiveLength=0;
                negativeLength=0;
            }
            if(num>0){
                positiveLength++;
                negativeLength+=(negativeLength>0)?1:0;
            }
            if(num<0){
                int tmp = negativeLength;
                negativeLength = (1+positiveLength);
                positiveLength = (tmp>0)?(1+tmp):0;
            }
            // cout<<num<<" "<<positiveLength<<" "<<negativeLength<<endl;
            result = max(result,positiveLength);
        }
        return result;
    }
};
// @lc code=end

