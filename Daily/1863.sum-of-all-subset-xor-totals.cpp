/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int maxBit = 0;
        // Determine the maximum bit necessary to represent all numbers
        for (int num : nums) {
            maxBit |= num;
        }
        
        // Each number appears in exactly half of the subsets, which is 1 << (n-1)
        int subsetCount = 1 << (n - 1);
        return maxBit * subsetCount;
    }
};
// @lc code=end

