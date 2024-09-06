/*
 * @lc app=leetcode id=1568 lang=cpp
 *
 * [1568] Minimum Number of Days to Disconnect Island
 */

// @lc code=start
class Solution {
private:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return;
        grid[i][j] = 0;
        for (const auto& dir : directions) {
            dfs(grid, i + dir[0], j + dir[1]);
        }
    }

    int countIslands(vector<vector<int>> grid) {
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    bool canDisconnectInOneDay(vector<vector<int>>& grid) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (countIslands(grid) != 1) {
                        return true;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return false;
    }

public:
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int islands = countIslands(grid);
        if (islands != 1) return 0;
        
        if (canDisconnectInOneDay(grid)) return 1;
        
        return 2;
    }
};
// @lc code=end

