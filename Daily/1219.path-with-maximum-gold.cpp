/*
 * @lc app=leetcode id=1219 lang=cpp
 *
 * [1219] Path with Maximum Gold
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
private:
    vector<vector<int>> grid;
    int m, n;
    int maxGold;

    void dfs(int x, int y, int currentGold) {

        int originalGold = grid[x][y];
        currentGold += originalGold;
        maxGold = max(maxGold, currentGold);

        // Mark the current cell as visited by setting it to 0
        grid[x][y] = 0;

        // Four possible directions: right, down, left, up
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0) {
                dfs(nx, ny, currentGold);
            }
        }
        grid[x][y] = originalGold;        // Backtrack: restore the gold amount to allow other paths to consider this cell
    }

public:
    int getMaximumGold(vector<vector<int>>& inputGrid) {
        grid = inputGrid;
        m = grid.size();
        n = grid[0].size();
        maxGold = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    dfs(i, j, 0);
                }
            }
        }
        return maxGold;
    }
};
// @lc code=end

