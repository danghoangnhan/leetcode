/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    perimeter += 4;
                    if (j > 0 && grid[i][j-1] == 1) perimeter -= 2; 
                    if (i > 0 && grid[i-1][j] == 1) perimeter -= 2;
                }
            }
        }
        return perimeter;
    }
};

// @lc code=end

