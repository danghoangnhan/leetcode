#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
class NumMatrix {
public:
    vector<vector<int>> rangesum;
    NumMatrix(vector<vector<int>>& matrix) {
        this->rangesum = matrix;    
        for (int i = 0; i < rangesum.size(); i++)
        {
            for (int j = 0; j < rangesum[i].size(); i++)
            {
                this->rangesum[i][j];
            }
            
        }
        
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

