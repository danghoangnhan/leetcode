/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
         if (node == NULL || node->next == NULL) {return;}
    
    ListNode* nextNode = node->next;   // The node that will be "deleted"
    node->val = nextNode->val;         // Copy the value from the next node to the current node
    node->next = nextNode->next;       // Skip over the next node, effectively deleting it

    delete nextNode;                   // Free the memory of the skipped node
    }
};
// @lc code=end

