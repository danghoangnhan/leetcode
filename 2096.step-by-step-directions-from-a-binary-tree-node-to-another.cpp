/*
 * @lc app=leetcode id=2096 lang=cpp
 *
 * [2096] Step-By-Step Directions From a Binary Tree Node to Another
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

class Solution {
public:
  string getDirections(TreeNode* root, int startValue, int destValue) {
    string startPath;
    string destPath;
    buildPath(root, startValue, startPath);
    buildPath(root, destValue, destPath);    

    while (!startPath.empty() && !destPath.empty() 
           && startPath.back() == destPath.back()) {
      startPath.pop_back();
      destPath.pop_back();
    }
    reverse(begin(destPath), end(destPath));
    return string(startPath.size(), 'U') + destPath;
  }
private:
  bool buildPath(TreeNode* root, int t, string& path) {
    if (!root) return false;
    if (root->val == t) return true;
    if (buildPath(root->left, t, path)) {
      path.push_back('L');
      return true;
    } else if (buildPath(root->right, t, path)) {
      path.push_back('R');
      return true;
    }
    return false;
  }
};
// @lc code=end

