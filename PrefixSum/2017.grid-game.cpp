/*
 * @lc app=leetcode id=2017 lang=cpp
 *
 * [2017] Grid Game
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
long long prefix0[50001], prefix1[50001];

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        
        int n = grid[0].size();
        long long ans = LLONG_MAX;

        memset(prefix0,0LL,n * sizeof(long long));
        memset(prefix1,0LL,n * sizeof(long long));

        for(int i = 0; i < n; i++){
            prefix0[i+1] = prefix0[i] + grid[0][i];
            prefix1[i+1] = prefix1[i] + grid[1][i];
        }
        

        for(int c = 0; c < n; c++){
            ans = min(ans, max(prefix0[n] - prefix0[c+1], prefix1[c]));
        }
        return ans;
    }
};
// @lc code=end

