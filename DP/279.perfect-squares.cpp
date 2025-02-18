#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+2,n);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int s=1;s<=i;s++){
                int currentVal = s*s;
                if (i-currentVal <0){break;}
                dp[i]=min(dp[i],1+dp[i-currentVal]);
            }
        }
        return dp[n];
    }
};
// @lc code=end

