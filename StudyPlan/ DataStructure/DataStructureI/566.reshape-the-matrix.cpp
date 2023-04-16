#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
class Solution {
public:
    int to_one_d(int i,int j,int row,int col){
        return i*col +j;
    }
    pair<int,int> to_two_d(int i,int row,int col){
        return make_pair(i/col,i%col);
    }
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> result(r,vector<int>(c,0));
        int original_row = mat.size();
        int original_col = mat[0].size();
        if (to_one_d(r-1,c-1,r,c)!=to_one_d(original_row-1,original_col-1,original_row,original_col)){
            return mat;
        }
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                pair<int,int>des = to_two_d(to_one_d(i,j,r,c),original_row,original_col);
                result[i][j]=mat[des.first][des.second];
            }
        }
        return result;
        
    }
};
// @lc code=end

