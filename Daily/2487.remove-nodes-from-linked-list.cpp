/*
 * @lc app=leetcode id=2487 lang=cpp
 *
 * [2487] Remove Nodes From Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* nextNode = removeNodes(head->next);

        if (nextNode == NULL || head->val >= nextNode->val){
            head->next = nextNode;
        }else{
            head = nextNode;
        }
        return head;
    }
};
// @lc code=end

