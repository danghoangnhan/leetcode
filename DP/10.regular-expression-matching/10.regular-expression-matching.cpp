/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

bool dp[21][21];

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_size = s.size(), p_size = p.size();
        

        fill_n(dp[0], 21 * 21, 0);

        dp[0][0] = true;
        for (int j = 1; j <= p_size; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        for (int i = 1; i <= s_size; ++i) {
            for (int j = 1; j <= p_size; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
            }
        }
        return dp[s_size][p_size];
    }
};
// @lc code=end

