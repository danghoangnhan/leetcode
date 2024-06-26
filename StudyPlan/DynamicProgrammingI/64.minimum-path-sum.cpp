#include <vector>
#include<math.h>
using namespace std;
/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int j = 1; j < grid.size(); j++){
                grid[j][0]+=grid[j-1][0];
            }
        for (int j = 1; j < grid[0].size(); j++){
                grid[0][j]+=grid[0][j-1];
            }
        for (int i = 1; i < grid.size(); i++){
            for (int j = 1; j < grid[i].size(); j++){
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[grid.size()-1][grid[0].size()-1]; 
    }
};
// @lc code=end

