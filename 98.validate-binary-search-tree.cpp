/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool solve(TreeNode* current,TreeNode*parent) {
        if (current==NULL)return true;
        if(!solve(current->left,parent)) return false;        
        if (parent!=NULL && parent->val <= current->val) return false;
        return  solve(current->right,current);
    }
    bool isValidBST(TreeNode* root) {
        return  solve(root,NULL);
    }
};
// @lc code=end

