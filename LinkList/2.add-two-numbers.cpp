#include <math>
using namespace std;
/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    int toNumber(ListNode* l1){
        int result =0;
        int exp=0;
        ListNode* currentPtr = l1;
        while (currentPtr!=0)
        {
            result += currentPtr->val*pow(10,exp);
            currentPtr = currentPtr->next;
        }
        return result;
    };
    ListNode* toNode(int Number){
        if (Number<10)
        {
            return new ListNode(Number,NULL);
        }
        ListNode* head  = new ListNode(Number%10,NULL);
        ListNode* currentPtr = head;
        Number %= 10;
        while (Number>0)
        {
            currentPtr->next = new ListNode(Number%10,NULL);
            Number%= 10;
            currentPtr = currentPtr->next;       
        }
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      return  toNode(toNumber(l1)+ toNumber(l2));       
    
    }
};
// @lc code=end

