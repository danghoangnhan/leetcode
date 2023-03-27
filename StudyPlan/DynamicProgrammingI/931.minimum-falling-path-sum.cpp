#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for (int i = 1; i < matrix.size(); i++){
            for (int  j= 0; j < matrix[i].size(); j++){
                int prev = matrix[i-1][j];
                if (j>0){
                    prev = min(prev,matrix[i-1][j-1]);
                }
                if (j<matrix[i].size()-1){
                    prev = min(prev,matrix[i-1][j+1]);
                }
                matrix[i][j] += prev;
            }
        }
        int result = matrix[matrix.size()-1][0];
        for (int i = 0; i < matrix[matrix.size()-1].size(); i++){
            result = min(result,matrix[matrix.size()-1][i]);
        }
        return result;
    }
};
// @lc code=end

