/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        postorderTraversal(root, result);
        return result;
    }

private:
    void postorderTraversal(Node* node, vector<int>& result) {
        if (!node) return;
        
        for (Node* child : node->children) {
            postorderTraversal(child, result);
        }
        result.push_back(node->val);
    }
};
// @lc code=end

