/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root!=NULL)
        {
            vector<int> left = postorderTraversal(root->left);
            vector<int> right = postorderTraversal(root->right);
            if (left.size()>0)result.insert(end(result), begin(left), end(left));
            if (right.size()>0)result.insert(end(result), begin(right), end(right));
            result.push_back(root->val);
        }
        return result;        
    }
};
// @lc code=end

