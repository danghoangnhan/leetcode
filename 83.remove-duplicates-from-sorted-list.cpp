#include <set>
using namespace std;
/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> visited;
        ListNode* previousePointer = NULL;
        ListNode* currentPointer = head;
        ListNode* tmpPointer ;
        while (currentPointer != NULL)
        {
            if (visited.count(currentPointer->val))
            {
                previousePointer->next = currentPointer->next;
                tmpPointer = currentPointer;
            }
            else{
                previousePointer = currentPointer;
                visited.insert(currentPointer->val);
            }
                currentPointer = currentPointer->next;

        }
        return head;
        
    }
};
// @lc code=end

