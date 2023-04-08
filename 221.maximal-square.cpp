#include <vector> 
#include <map>
using namespace std;
/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int helper(int row,int column){
        if (row>=this->rows ||column>=this->cols){return 0;}
                if (this->cache[row][column]==-1){
                    int down = helper(row+1,column);
                    int right = helper(row,column+1);
                    int diag = helper(row+1,column+1);
                    this->cache[row][column]=(this->matrix[row][column]=='1')? 1 + min(down,min(right,diag)):0;
                }
        return this->cache[row][column];
    }
    int maximum(vector<vector<int>>& matrix){
        int result = matrix[0][0];
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                result = max(result,matrix[i][j]);
            }
        }
        return result;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        this->cols = matrix[0].size();
        this->rows = matrix.size();
        this->matrix = matrix;
        this->cache = new vector(rows,vector<int>(cols,-1));
        helper(0,0);
        int value = maximum(this->cache);   
        return value * value;
    }
    private:
        int cols,rows;
        vector<vector<int>>* cache;
        vector<vector<char>>& matrix;
};
// @lc code=end