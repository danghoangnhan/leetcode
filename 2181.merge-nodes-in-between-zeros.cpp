/*
 * @lc app=leetcode id=2181 lang=cpp
 *
 * [2181] Merge Nodes in Between Zeros
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* current = head->next; // skip the initial zero
        ListNode* mergedHead = current; // the new head of the merged list
        ListNode* mergedTail = current; // the current tail of the merged list

        int sum = 0;
        while (current != nullptr) {
            if (current->val == 0) {
                mergedTail->val = sum;
                mergedTail->next = current->next;
                mergedTail = mergedTail->next;
                sum = 0;
            } else {
                // Accumulate values
                sum += current->val;
            }
            current = current->next;
        }
        if (mergedTail != nullptr && mergedTail->val == 0) {
            mergedTail = nullptr;
        }
        return mergedHead;
    }
};
// @lc code=end

