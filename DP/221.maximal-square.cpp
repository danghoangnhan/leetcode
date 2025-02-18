#include <vector> 
#include <map>
#include <math.h>
using namespace std;
/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()){return 0;}
        vector<vector<int>> sizes(matrix.size(),vector<int>(matrix[0].size(),0));
        int result =0;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                sizes[i][j]=matrix[i][j]-'0';
                if (!sizes[i][j])continue;
                if (i>0 &&  j>0){
                    sizes[i][j] = min(min(
                        sizes[i-1][j],
                        sizes[i][j-1]),
                        sizes[i-1][j-1])+1;
                }
                result = max(result,sizes[i][j]*sizes[i][j]);
            }
        }
        return result;
        
    }
};
// @lc code=end