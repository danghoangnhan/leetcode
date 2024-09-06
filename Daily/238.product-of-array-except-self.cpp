/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        // Calculate left products directly into the answer array
        for (int i = 1; i < n; ++i) {
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        // Calculate right products and update the answer array
        int rightProduct = 1; // this keeps track of the product of elements to the right of the index
        for (int i = n - 1; i >= 0; --i) {
            answer[i] = answer[i] * rightProduct; // Multiply the left product by the right product
            rightProduct *= nums[i]; // Update the right product
        }

        return answer;
    }
};
// @lc code=end

