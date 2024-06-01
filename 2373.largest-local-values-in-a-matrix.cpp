/*
 * @lc app=leetcode id=2373 lang=cpp
 *
 * [2373] Largest Local Values in a Matrix
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2));

        // Iterate over each possible top-left corner of a 3x3 submatrix
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                int maxVal = 0;
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        maxVal = max(maxVal, grid[i + x][j + y]);
                    }
                }
                maxLocal[i][j] = maxVal;
            }
        }

        return maxLocal;
    }
};
// @lc code=end

