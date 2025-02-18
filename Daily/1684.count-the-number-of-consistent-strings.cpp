/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        vector<bool> allowedChars(26, false);
        for (char c : allowed) {
            allowedChars[c - 'a'] = true;
        }
        
        int count = 0;
        
        for (const string& word : words) {
            bool isConsistent = true;
            for (char c : word) {
                if (!allowedChars[c - 'a']) {
                    isConsistent = false;
                    break;
                }
            }
            if (isConsistent) {
                count++;
            }
        }
        
        return count;
    }
};
// @lc code=end

