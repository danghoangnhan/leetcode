/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count[3] = {0, 0, 0}; 
        int distinct = 0;
        int left = 0; 
        int result = 0;
        for (int right = 0; right < n; ++right) {
            int c = s[right] - 'a';
            count[c]++;
            if (count[c] == 1) {
                distinct++;
            }

            while (distinct == 3) {
                result += (n - right);
                int leftChar = s[left] - 'a';
                count[leftChar]--;
                if (count[leftChar] == 0) {
                    distinct--;
                }
                left++;
            }
        }
        return (int)result;
    }
};
// @lc code=end

