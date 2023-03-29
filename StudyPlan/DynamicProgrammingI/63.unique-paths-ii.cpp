#include<vector>
#include<iostream>
using namespace std;
/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    void display(vector<vector<int>>& matrix){
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]){
            return 0;
        }
        vector<vector<int>> ways(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
        for (int i = 0; i < ways.size(); i++){
            if(obstacleGrid[i][0]==1){
                ways[i][0]=0;
            }
            else if (i>0 && ways[i-1][0]==0){
                ways[i][0] =0;
            }else{
                ways[i][0] =1;
            }
            
        }
        for (int i = 0; i < obstacleGrid[0].size(); i++){
            if(obstacleGrid[0][i]==1){
                ways[0][i] =0;
            }
            else if (i>0 && ways[0][i-1]==0){
                ways[0][i] =0;
            }else{
                ways[0][i] =1;
            }
        }
        for (int i = 1; i < obstacleGrid.size(); i++){
            for (int j = 1; j < obstacleGrid[i].size(); j++){
                // cout<<obstacleGrid[i][0]<<" "<<obstacleGrid[i-1][j]<<" "<<obstacleGrid[i][j-1]<<endl;
                if(obstacleGrid[i][j]){
                    ways[i][j] =0;
                    continue;
                }
                if(obstacleGrid[i-1][j]==0){
                    ways[i][j]+=ways[i-1][j];
                }
                if(obstacleGrid[i][j-1]==0){
                    ways[i][j]+=ways[i][j-1];
                }
            }
        }
        // display(ways);
        return ways[ways.size()-1][ways[0].size()-1]; 
    }
};
// @lc code=end

