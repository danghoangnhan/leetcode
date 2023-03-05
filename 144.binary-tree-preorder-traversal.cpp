#include<vector>
using namespace std;
/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root!=NULL)
        {
            result.push_back(root->val);
            vector<int> left = preorderTraversal(root->left);
            vector<int> right = preorderTraversal(root->right);
            if (left.size()>0)result.insert(end(result), begin(left), end(left));
            if (right.size()>0)result.insert(end(result), begin(right), end(right));
        }
        return result;        
    }
};
// @lc code=end

