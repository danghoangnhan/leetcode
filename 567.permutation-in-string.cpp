/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
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
        
        return false;
    }
};
// @lc code=end

