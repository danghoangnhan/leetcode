/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* currentNode = root;
        while (currentNode!=nullptr){
            if (p->val>currentNode->val && q->val>currentNode->val){
                currentNode = currentNode->right;
            }
            else if (p->val<currentNode->val && q->val<currentNode->val){
                currentNode = currentNode->left;
            }
            else{
                break;
            }
                
        }
        return currentNode;    
    }
};
// @lc code=end

