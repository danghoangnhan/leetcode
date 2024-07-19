/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
    
        vector<int> lucky;
        vector<int> row_mins(rows, INT_MAX);
        vector<int> col_maxs(cols, INT_MIN);
    
        // Find minimum in each row
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                row_mins[i] = min(row_mins[i], matrix[i][j]);
            }
        }
    
        // Find maximum in each column
        for (int j = 0; j < cols; ++j) {
            for (int i = 0; i < rows; ++i) {
                col_maxs[j] = max(col_maxs[j], matrix[i][j]);
            }
        }
    
        // Check for lucky numbers
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == row_mins[i] && matrix[i][j] == col_maxs[j]) {
                    lucky.push_back(matrix[i][j]);
                }
            }
        }
    
    return lucky;
    }
};
// @lc code=end

