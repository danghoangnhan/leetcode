#include <limits>
using  namespace std;
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
    bool solve(TreeNode* current,long long int left,long long int right) {
        if (current==nullptr)return true;

        if(!(current->val<right && current->val>left)) return false;        
        return      solve(current->left,left,current->val) 
                &&  solve(current->right,current->val,right);
    }
    bool isValidBST(TreeNode* root) {
        return  solve(root,LLONG_MIN,LLONG_MAX);
    }
};
// @lc code=end

