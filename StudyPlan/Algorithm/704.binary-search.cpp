#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int mid;
        while (hi - lo > 1) {
            int mid = (hi + lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        if (nums[lo] == target) {
            return lo;
        }
        else if (nums[hi] == target) {
            return hi;
        }
        else {
            return -1;
        }
    }
};
// @lc code=end

