/*
 * @lc app=leetcode id=2196 lang=cpp
 *
 * [2196] Create Binary Tree From Descriptions
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
#include  "bits/stdc++.h"
using namespace std;

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for (const auto& desc : descriptions) {
            int parent = desc[0], child = desc[1], isLeft = desc[2];

            if (nodes.find(parent) == nodes.end()) 
                nodes[parent] = new TreeNode(parent);
            if (nodes.find(child) == nodes.end())
                nodes[child] = new TreeNode(child);

            if (isLeft) {
                nodes[parent]->left = nodes[child];
            } else {
                nodes[parent]->right = nodes[child];
            }
            children.insert(child);
        }

        TreeNode* root = nullptr;
        for (const auto& node : nodes) {
            if (children.find(node.first) == children.end()) {
                root = node.second;
                break;
            }
        }
        return root;
    }
};
// @lc code=end

