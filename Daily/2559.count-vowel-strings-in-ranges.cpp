/*
 * @lc app=leetcode id=2559 lang=cpp
 *
 * [2559] Count Vowel Strings in Ranges
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        bitset<128> vowels;
        vowels['a'] = vowels['e'] = vowels['i'] = vowels['o'] = vowels['u'] = 1;
        
        vector<int> result(queries.size());
        vector<int> prefix(words.size());
        
        prefix[0] = (vowels[words[0].front()] && vowels[words[0].back()]);
        
        for(int i = 1; i < words.size(); i++) {
            prefix[i] = prefix[i-1] + 
                       (vowels[words[i].front()] && vowels[words[i].back()]);
        }
        
        for(int i = 0; i < queries.size(); i++) {
            int left = queries[i][0], right = queries[i][1];
            result[i] = prefix[right] - (left > 0 ? prefix[left-1] : 0);
        }
        return result;
    }
};
// @lc code=end

