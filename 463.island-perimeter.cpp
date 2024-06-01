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
                    // Each land cell initially has 4 potential perimeter sides
                    perimeter += 4;
                    if (j > 0 && grid[i][j-1] == 1) perimeter -= 2; // Check cell to the left
                    if (i > 0 && grid[i-1][j] == 1) perimeter -= 2;  // Check cell above
                }
            }
        }
        
        return perimeter;
    }
};

// @lc code=end

