/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            
            if (first != second) {
                pq.push(first - second);
            }
        }
        
        return pq.empty() ? 0 : pq.top();
    }
};
// @lc code=end

