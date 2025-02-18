/*
 * @lc app=leetcode id=2331 lang=cpp
 *
 * [2331] Evaluate Boolean Binary Tree
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
    bool evaluateTree(TreeNode* root) {
        // Base case: if the node is a leaf node, evaluate it
        if (!root->left && !root->right) {
            return root->val == 1;  // Leaf nodes are either 0 or 1
        }

        // Recursively evaluate the left and right children
        bool left_val = evaluateTree(root->left);
        bool right_val = evaluateTree(root->right);

        // Apply the operation based on the value of the node
        if (root->val == 2) {  // OR operation
            return left_val || right_val;
        } else if (root->val == 3) {  // AND operation
            return left_val && right_val;
        }
        return false;// Ideally should never reach here if input is always correct as per problem statement
    }
};
// @lc code=end

