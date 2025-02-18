/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int> lastSeen(256, -1);  // Assuming ASCII characters
        int maxLength = 0;
        int start = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (lastSeen[s[i]] >= start) {
                start = lastSeen[s[i]] + 1;
            }
            lastSeen[s[i]] = i;
            maxLength = max(maxLength, i - start + 1);
        }
        
        return maxLength;
    }
};


// @lc code=end

