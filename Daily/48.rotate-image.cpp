#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int colums = matrix[0].size();
        int rows = matrix.size();
        vector<vector<int>>result (rows,vector<int>(colums));
                for (int i = 0; i < rows; i++){
                    for (int j = 0; j < colums; j++){
                        result[i][j] = matrix[i][j];
                    }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < colums; j++)
            {
                matrix[i][j] = result[colums-1-j][i];
            }
        }
    }
};
// @lc code=end

