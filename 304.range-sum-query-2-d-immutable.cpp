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
    NumMatrix(vector<vector<int>>& matrix) {
        this->rangesum.clear();
        if (matrix.empty()) return;
        this->rangesum = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 1; i <= matrix.size(); ++i)
            for (int j = 1; j <= matrix[i].size(); ++j)
                this->rangesum[i][j] = matrix[i - 1][j - 1]
                 + this->rangesum[i - 1][j]
                 + this->rangesum[i][j - 1]
                 - this->rangesum[i - 1][j - 1] ;
        }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return this->rangesum[row2 + 1][col2 + 1] 
        - this->rangesum[row1][col2 + 1] 
        - this->rangesum[row2 + 1][col1] 
        + this->rangesum[row1][col1];
    }
private:
    vector<vector<int>> rangesum;
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

