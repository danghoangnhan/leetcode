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
    ListNode* recursive(ListNode* head) {
            if (!head) return nullptr;
            
            head->val *= 2;
            if (head->next) {
                ListNode* nextNode = recursive(head->next);
                if (nextNode->val >= 10) {
                    head->val += nextNode->val / 10;
                    nextNode->val %= 10;
                }
            }

            return head;
        }

    ListNode* doubleIt(ListNode* head) {
        if (!head) return nullptr;

        head = recursive(head);
        if (head->val >= 10) {
            ListNode* newHead = new ListNode(head->val / 10);
            head->val %= 10;
            newHead->next = head;
            return newHead;
        }

        return head;
    }
};