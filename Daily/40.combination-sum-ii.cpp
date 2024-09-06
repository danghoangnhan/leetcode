/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(vector<int>& candidates, int target, int start) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1]) continue; // Skip duplicates
            if (candidates[i] > target) break; // Optimization: no need to continue if current number is greater than target

            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates and optimize
        backtrack(candidates, target, 0);
        return result;
    }
};
// @lc code=end

