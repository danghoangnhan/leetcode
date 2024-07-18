/*
 * @lc app=leetcode id=1530 lang=cpp
 *
 * [1530] Number of Good Leaf Nodes Pairs
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        return dfs(root, distance).second;
    }
private:
    pair<vector<int>, int> dfs(TreeNode* node, int distance) {
        if (!node) {
            return {vector<int>(distance + 1, 0), 0};
        }

        if (!node->left && !node->right) {
            vector<int> depths(distance + 1, 0);
            depths[0] = 1;
            return {depths, 0};
        }

        auto [leftDepths, leftPairs]    = dfs(node->left, distance);
        auto [rightDepths, rightPairs]  = dfs(node->right, distance);

        int totalPairs = leftPairs + rightPairs;
        vector<int> depths(distance + 1, 0);

        for (int i = 0; i <= distance; ++i) {
            for (int j = 0; j <= distance; ++j) {
                if (i + j + 2 <= distance) {
                    totalPairs += leftDepths[i] * rightDepths[j];
                }
            }
        }

        for (int i = 0; i < distance; ++i)
            depths[i + 1] = leftDepths[i] + rightDepths[i];
            
        return {depths, totalPairs};
    }
};
// @lc code=end

