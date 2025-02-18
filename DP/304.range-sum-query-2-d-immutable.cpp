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
        this->rangesum = vector<vector<int>>(matrix.size() , vector<int>(matrix[0].size() , 0));
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(i == 0 && j == 0) {
                    rangesum[i][j] = matrix[0][0];
                } else if(i == 0) {
                    rangesum[i][j] = rangesum[i][j-1] + matrix[i][j];
                } else if(j == 0) {
                    rangesum[i][j] = rangesum[i-1][j] + matrix[i][j];
                } else {
                    rangesum[i][j] = rangesum[i-1][j] 
                    + rangesum[i][j-1] 
                    + matrix[i][j] 
                    - rangesum[i-1][j-1];
                }
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 == 0) {
            return rangesum[row2][col2];
        } else if(row1 == 0) {
            return rangesum[row2][col2] - rangesum[row2][col1-1];
        } else if(col1 == 0) {
            return rangesum[row2][col2] - rangesum[row1-1][col2];
        } else {
            return rangesum[row2][col2] 
            - rangesum[row1-1][col2] 
            - rangesum[row2][col1-1] 
            + rangesum[row1-1][col1-1];
        }
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

