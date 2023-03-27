/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
               vector<vector<int>>result;
        for (int  i = 1; i <= rowIndex+1; i++){
            result.push_back(vector<int>(i,0));
        }
        result[0][0] = 1;
        for (int i = 1; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                if ( j ==0 || j == result[i].size()-1)
                {
                    result[i][j] = 1;
                }
                else{
                    result[i][j] = result[i-1][j] + result[i-1][j-1]; 
                }
                
            }
            
        }
        return result[rowIndex]; 
    }
};
// @lc code=end

