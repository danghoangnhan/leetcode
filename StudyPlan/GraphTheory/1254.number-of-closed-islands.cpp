/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int result = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        for (int i = 0; i < grid.size(); i++) {
            dfs(grid, i, 0, visited);         
            dfs(grid, i, grid[0].size() - 1, visited);     
        }

        for (int i = 0; i < grid[0].size(); i++) {
            dfs(grid, 0, i, visited);         
            dfs(grid, grid.size() - 1, i, visited);    
        }

        for (int i = 1; i < grid.size()-1; i++) {
            for (int j = 1; j < grid[i].size()-1; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    result++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        return result;
    }
    void dfs(
        vector<vector<int>>& grid,
        int i,int j, vector<vector<bool>>& visited) {
        if (i < 0 
            || i >= grid.size() 
            || j <0 
            || j >= grid[i].size() 
            || visited[i][j] 
            || grid[i][j] == 1) {
            return;
        }
        visited[i][j] = true;
        dfs(grid, i - 1, j, visited);
        dfs(grid, i + 1, j, visited);
        dfs(grid, i, j - 1, visited);
        dfs(grid, i, j + 1, visited);
    }
};
// @lc code=end

