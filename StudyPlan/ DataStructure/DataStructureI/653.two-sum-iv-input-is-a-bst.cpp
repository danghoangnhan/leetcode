#include<map>
using namespace std;
/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
    map<int, int> maps;
    bool findTarget(TreeNode* root, int k) {
        if(root==nullptr) return false;
        if (this->maps.count(root->val)){return true;}
        this->maps[k - root->val] = root->val;
        bool foundLeft = findTarget(root->left,k);
        if (foundLeft) return foundLeft;
        bool foundRight = findTarget(root->right,k);
        return foundRight;
    }
};
// @lc code=end

