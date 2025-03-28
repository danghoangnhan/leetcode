/*
 * @lc app=leetcode id=2503 lang=cpp
 *
 * [2503] Maximum Number of Points From Grid Queries
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size(), k = queries.size();
        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < k; i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        
        vector<int> ans(k, 0);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        int count = 0;
        vector<int> dirs = {0, 1, 0, -1, 0};
        
        for (auto &q: sortedQueries) {
            int currQuery = q.first;
            int queryIndex = q.second;

            while (!pq.empty() && get<0>(pq.top()) < currQuery) {
                auto [val, x, y] = pq.top();
                pq.pop();
                count++;
                
                for (int d = 0; d < 4; d++) {
                    int nx = x + dirs[d], ny = y + dirs[d+1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny])
                        continue;
                    visited[nx][ny] = true;
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
            ans[queryIndex] = count;
        }
        return ans;
    }
};
// @lc code=end

