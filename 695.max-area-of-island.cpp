#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */
// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int h = grid.size();
        if (h == 0) return 0;
        int w = grid[0].size();
        
        int ans = 0;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                ans = max(ans, area(grid, j, i, w, h));
        return ans;
    }
    int area(vector<vector<int>>& grid, int x, int y, int w, int h) {
        if (x < 0 || y < 0 || x >= w || y >= h || grid[y][x] == 0) return 0;
        
        grid[y][x] = 0;
        
        return area(grid, x - 1, y, w, h) 
             + area(grid, x + 1, y, w, h)
             + area(grid, x, y - 1, w, h)
             + area(grid, x, y + 1, w, h)
             + 1;            
    }
};
// @lc code=end

