/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(),nums.end());
        while(minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};
// @lc code=end

