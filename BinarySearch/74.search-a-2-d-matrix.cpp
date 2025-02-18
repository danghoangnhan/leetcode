/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0, hi = matrix.size() - 1;
        int mid;
        while (hi - lo > 1) {
            int mid = (hi + lo) / 2;
            if (matrix[mid][matrix[0].size()-1] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        if (search(matrix[lo],target)>-1) {
            return true;
        }
        else if (search(matrix[hi],target)>-1) {
            return true;
        }
        else {
            return false;
        }
    }
};
// @lc code=end

