#include <vector>
#include <math.h>
using namespace std;
/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root==nullptr){
            return vector<vector<int>>(0,vector<int>(0)); 
        }
        
        vector<vector<vector<int>>> children;
        
        if(root->left!=nullptr){children.push_back(levelOrder(root->left));}
        if(root->right!=nullptr){children.push_back(levelOrder(root->right));}
        
        int maxOrder = 0;
        for (auto child:children){
            maxOrder = max(maxOrder,int(child.size()));
        }
        maxOrder++;

        vector<vector<int>> result(maxOrder,vector<int>(0));
        result[0].push_back(root->val);
        
        for (vector<vector<int>> child:children){
            for (int i = 0; i < child.size(); i++){
                vector<int> entryLevel = child[i];
                    for (int element:entryLevel){
                        result[i+1].push_back(element);
                    }
            }
        }
        return result;
    }
};
// @lc code=end

