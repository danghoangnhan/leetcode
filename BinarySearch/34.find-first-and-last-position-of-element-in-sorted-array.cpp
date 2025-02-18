#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target,bool left) {
        int lo = 0, hi = nums.size() - 1;
        int mid;
        int result =-1;
        while (hi>=lo) {
            int mid = (hi + lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            }
            else if(nums[mid] > target){
                hi = mid-1;
            }else{
                result = mid;
                if (left){
                    hi = mid - 1;
                }
                else{
                    lo  = mid + 1;
                }
                
            }
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>result;
        result.push_back(search(nums,target,true));
        result.push_back(search(nums,target,false));
        return result;
    }
};
// @lc code=end

