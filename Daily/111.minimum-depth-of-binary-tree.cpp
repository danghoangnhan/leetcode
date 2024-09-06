#include <limits>

/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int imax = 1<<30;
    int minDepth(TreeNode* root) {    
        if (root==NULL){return 0;}
        int leftSide =(root->left==NULL)?0 : minDepth(root->left);
        int rightSide =(root->right==NULL)?0 : minDepth(root->right);
        if (leftSide>0 && rightSide ==0)
        {
            return 1+ leftSide;
        }
        else if (leftSide==0 && rightSide >0)
        {
            return 1+ rightSide;
        }
        return 1+ min(leftSide,rightSide); 
    }
};
// @lc code=end

