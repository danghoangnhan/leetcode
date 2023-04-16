/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result;
        if(list2==nullptr && list1 ==nullptr)return nullptr;
        if(list1==nullptr)return list2;
        if(list2==nullptr)return list1;
        
        if (list1->val<=list2->val){
            ListNode* nextPtr = mergeTwoLists(list1->next, list2);
            list1->next=nextPtr;
            result = list1;
        }
        else{
            ListNode* nextPtr = mergeTwoLists(list2->next, list1);
            list2->next=nextPtr;
            result = list2;
        }
        return result;
    }
};
// @lc code=end

