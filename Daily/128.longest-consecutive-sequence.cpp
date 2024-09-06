/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())return 0;

        unordered_set<int> num_set(nums.begin(), nums.end());
        int max_length = 0;

        for (int num : num_set) {
            // Only start counting if `num-1` is not in the set (new sequence start)
            if (num_set.find(num - 1) == num_set.end()) {
                int current_num = num;
                int current_length = 1;

                // Increment sequence while consecutive numbers exist in the set
                while (num_set.find(current_num + 1) != num_set.end()) {
                    current_num += 1;
                    current_length += 1;
                }

                // Update the maximum length found
                max_length = max(max_length, current_length);
            }
        }
        return max_length;
    }
};
// @lc code=end