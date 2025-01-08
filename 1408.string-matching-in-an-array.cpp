/*
 * @lc app=leetcode id=1408 lang=cpp
 *
 * [1408] String Matching in an Array
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> result;
        int n = words.size();
        
        // Sort array by string length to optimize checking
        // Shorter strings can only be substrings of longer ones
        sort(words.begin(), words.end(), 
            [](const string& a, const string& b) {
                return a.length() < b.length();
            });
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                // If current word is substring of a longer word
                if(words[j].find(words[i]) != string::npos) {
                    result.insert(words[i]);
                    break;
                }
            }
        }
        return vector<string>(result.begin(), result.end());
    }
};
// @lc code=end

