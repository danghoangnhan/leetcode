/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxCount = 0;
        int start = 0;
        int maxLength = 0;
        
        for (int end = 0; end < s.length(); end++) {
            count[s[end] - 'A']++;
            maxCount = max(maxCount, count[s[end] - 'A']);
            
            if (end - start + 1 - maxCount > k) {
                count[s[start] - 'A']--;
                start++;
            }
            
            maxLength = max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};
// @lc code=end

