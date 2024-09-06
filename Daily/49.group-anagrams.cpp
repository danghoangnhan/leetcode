/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
// @lc code=start

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string generateKey(const string& str) {
            vector<int> count(26, 0); // Vector to count character frequencies
            for (char c : str) {
                count[c - 'a']++;
            }
            string key = "";
            for (int i = 0; i < 26; i++) {
                if (count[i] > 0) {
                    key += string(count[i], 'a' + i);
                }
            }
            return key;
        }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap; // Using unordered_map for better performance
        vector<vector<string>> result;

        for (const string& str : strs) {
            string key = generateKey(str);
            anagramMap[key].push_back(str);
        }
        
        for (auto& pair : anagramMap) {
            result.push_back(pair.second);
        }
        return result;
    }
};
// auto init = []() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     return 'c';
// }();
// @lc code=end

