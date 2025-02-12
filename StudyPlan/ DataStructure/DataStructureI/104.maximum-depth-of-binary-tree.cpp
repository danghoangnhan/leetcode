#include <math.h>
using namespace std;
/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        if (root==NULL){return 0;}
        int leftSide =(root->left==NULL)?0 : maxDepth(root->left);
        int rightSide =(root->right==NULL)?0 : maxDepth(root->right);
        return 1+ max(leftSide,rightSide); 
    }
};
// @lc code=end

