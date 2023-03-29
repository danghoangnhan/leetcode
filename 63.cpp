#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> ways(obstacleGrid.size(),vector<int>(obstacleGrid[0].size()));
        for (int i = 0; i < obstacleGrid.size(); i++){
            if(obstacleGrid[i][0]==1 || ways[i-1][0]==0){
                ways[i][0] =0;
                continue;
            }
            ways[i][0] =1;
        }
        for (int i = 0; i < obstacleGrid[0].size(); i++){
            if(obstacleGrid[0][i]==1||ways[0][i-1]==0){
                ways[0][i] =0;
                continue;
            }
            ways[0][i] =1;
        }
        for (int i = 1; i < obstacleGrid.size(); i++){
            for (int j = 1; j < obstacleGrid[0].size(); j++){
                if(obstacleGrid[i][0]){
                    ways[i][j] =0;
                    continue;
                }
                if(!obstacleGrid[i-1][j]){
                    ways[i][j]+=ways[i-1][j];
                }
                if(!obstacleGrid[i][j-1]){
                    ways[i][j]+=ways[i][j-1];
                }
            }
        }
        return ways[obstacleGrid.size()-1][obstacleGrid[0].size()-1];   
    }
};