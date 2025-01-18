/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
#include "bits/stdc++.h"
using namespace std;

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (curr->val >= low && curr->val <= high) {
                sum += curr->val;
            }
            
            if (curr->left && curr->val > low) {
                q.push(curr->left);
            }
            
            if (curr->right && curr->val < high) {
                q.push(curr->right);
            }
        }
        return sum;
    }
};
// @lc code=end

