/*
 * @lc app=leetcode id=1092 lang=cpp
 *
 * [1092] Shortest Common Supersequence 
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    
    int lcs[1002][1002] = {};

void longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                if (text1[i-1] == text2[j-1])
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                else
                    lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int m =str1.size();
        int n = str2.size();
        
        longestCommonSubsequence(str1,str2);

        int i = m, j = n;
        string result = "";
        
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                result += str1[i - 1];
                i--, j--;
            } else if (lcs[i - 1][j] > lcs[i][j - 1]) {
                result += str1[i - 1];
                i--;
            } else {
                result += str2[j - 1];
                j--;
            }
        }
        while (i > 0) result += str1[--i];
        while (j > 0) result += str2[--j];
        
        reverse(result.begin(), result.end());
        return result;

    }
};
// @lc code=end

