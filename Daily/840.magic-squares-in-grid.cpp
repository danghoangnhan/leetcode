/*
 * @lc app=leetcode id=840 lang=cpp
 *
 * [840] Magic Squares In Grid
 */

// @lc code=start
class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        // Check if all numbers are from 1 to 9
        vector<bool> used(10, false);
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                int num = grid[i][j];
                if (num < 1 || num > 9 || used[num]) return false;
                used[num] = true;
            }
        }
        
        // Check row sums
        int sum = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        for (int i = row + 1; i < row + 3; i++) {
            if (grid[i][col] + grid[i][col+1] + grid[i][col+2] != sum) return false;
        }
        
        // Check column sums
        for (int j = col; j < col + 3; j++) {
            if (grid[row][j] + grid[row+1][j] + grid[row+2][j] != sum) return false;
        }
        
        // Check diagonals
        if (grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2] != sum) return false;
        if (grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col] != sum) return false;
        
        return true;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        
        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
// @lc code=end

