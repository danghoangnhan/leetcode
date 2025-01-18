/*
 * @lc app=leetcode id=1368 lang=cpp
 *
 * [1368] Minimum Cost to Make at Least One Valid Path in a Grid
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();        

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        deque<pair<int,int>> dq;
        
        dist[0][0] = 0;
        dq.push_back({0,0});

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            
            int currCost = dist[r][c];
            
            for (int i = 0; i < 4; i++) {
                
                int nr = r + dirs[i].first;
                int nc = c + dirs[i].second;
                
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    continue;
                }
                
                int extra = (grid[r][c] == (i + 1)) ? 0 : 1;
                int newCost = currCost + extra;
                
                if (newCost < dist[nr][nc]) {
                    dist[nr][nc] = newCost;
                    
                    if (extra == 0) {
                        dq.push_front({nr, nc});
                    } else {
                        dq.push_back({nr, nc});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};

// @lc code=end

