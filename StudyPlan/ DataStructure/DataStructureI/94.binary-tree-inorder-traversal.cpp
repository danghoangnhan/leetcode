/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root!=NULL)
        {
            vector<int> left = inorderTraversal(root->left);
            vector<int> right = inorderTraversal(root->right);
            if (left.size()>0)result.insert(end(result), begin(left), end(left));
            result.push_back(root->val);
            if (right.size()>0)result.insert(end(result), begin(right), end(right));
        }
        return result;      
    }
};
// @lc code=end

