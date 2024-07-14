/*
 * @lc app=leetcode id=2058 lang=cpp
 *
 * [2058] Find the Minimum and Maximum Number of Nodes Between Critical Points
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
 #include "bits/stdc++.h"
 using namespace std;

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* currentNode = head;
        ListNode* nextNode = head->next;
        vector<int>result={INT_MIN,INT_MAX};
        int lastIndexValue = -1;
        int index = 0;
        int currentDistance;
        vector<int> criticalPoints;

        while(nextNode->next != NULL){
            if(     (currentNode->val < nextNode->val && nextNode->val > nextNode->next->val)
                ||  (currentNode->val > nextNode->val && nextNode->val < nextNode->next->val)){
                if(lastIndexValue == -1){
                    criticalPoints.push_back(index);
                }
            }
            currentNode = nextNode;
            nextNode = nextNode->next;
            index ++;
        }

        if (criticalPoints.size() < 2) {return {-1, -1};}


        int minDistance = INT_MAX;
        int maxDistance = criticalPoints.back() - criticalPoints.front();
        
        for (int i = 1; i < criticalPoints.size(); ++i) {
            minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
        }
        
        return {minDistance, maxDistance};

        return result;
    }
};
// @lc code=end

