/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool dfs(TreeNode* left,TreeNode* right){
        if(left==nullptr && right ==nullptr)return true;
        if(left==nullptr || right ==nullptr)return false;
        return (left->val == right->val) && dfs(left->left,right->right) && dfs(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left,root->right);
    }
};
// @lc code=end

