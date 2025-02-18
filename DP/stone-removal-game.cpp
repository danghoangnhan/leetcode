#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10) return false;
        vector<vector<int>> dp(51, vector<int>(11, -1));
        return solve(n, 10, true, dp);
    }
    bool solve(int stones, int mustRemove, bool isAlice, vector<vector<int>>& dp) {
        if (stones < mustRemove) return false;
        if (stones == mustRemove) return true;
        if (dp[stones][mustRemove] != -1) return dp[stones][mustRemove];
        
        int remaining = stones - mustRemove;
        int nextRemove = (mustRemove > 1) ? mustRemove - 1 : 1;
        
        bool result = !solve(remaining, nextRemove, !isAlice, dp);
        dp[stones][mustRemove] = result;
        return result;
    }
};