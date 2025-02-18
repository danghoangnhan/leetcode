#include <vector>
#include <math.h>
using namespace std;
/*
 * @lc app=leetcode id=1314 lang=cpp
 *
 * [1314] Matrix Block Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> result(mat.size(),vector<int>(mat[0].size(),0));
        for (int i = 0; i < mat.size(); i++){
            for (int j = 0; j < mat[i].size(); j++){
                int leftBound = max(j-k,0);
                int rightBound = min(j+k+1,int(mat[i].size()));
                int highBound = max(i-k,0);
                int lowBound = min(i+k+1,int(mat.size()));
                for (int rows = highBound; rows < lowBound; rows++){
                    for (int cols = leftBound; cols < rightBound; cols++){
                        result[rows][cols]+= mat[i][j];
                    }
                }    
            }
        }
        return result;
    }
};
// @lc code=end

