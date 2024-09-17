/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return sqrt(a[0]*a[0] + a[1]*a[1]) > sqrt(b[0]*b[0] + b[1]*b[1]);
        };        
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        
        for (const auto& point : points) {
            pq.push(point);
        }
        
        vector<vector<int>> result;
        while (!pq.empty() && result.size() <k) {
            
            result.push_back(pq.top());
            pq.pop();
        }
        
        return result;
    }
};
// @lc code=end

