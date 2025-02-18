/*
 * @lc app=leetcode id=1765 lang=cpp
 *
 * [1765] Map of Highest Peak
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> result(m,vector<int>(n,0));
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j] &&){
                    q.emplace(make_pair({i,j}));
                    visited[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            
        }
        return result;
    }
};
// @lc code=end

