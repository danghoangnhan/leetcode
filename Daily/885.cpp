/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result = {{rStart, cStart}};
        int total = rows * cols;
        
        if (total == 1) return result;
        
        int steps = 0;
        int direction = 0;
        int dx[4] = {1, 0, -1, 0};  // East, South, West, North
        int dy[4] = {0, 1, 0, -1};
        
        while (result.size() < total) {
            if (direction == 0 || direction == 2) steps++;  // Increase steps when moving East or West
            
            for (int i = 0; i < steps; i++) {
                rStart += dy[direction];
                cStart += dx[direction];
                
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    result.push_back({rStart, cStart});
                    if (result.size() == total) return result;
                }
            }
            
            direction = (direction + 1) % 4;  // Change direction
        }
        
        return result;
    }
};
// @lc code=end

