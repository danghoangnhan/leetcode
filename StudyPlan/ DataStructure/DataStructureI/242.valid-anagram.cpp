#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>alphabet_s(26,0);
        vector<int>alphabet_t(26,0);
        for (auto word:s){
            alphabet_s[word-'a']++;
        }
        for (auto word:t){
            alphabet_t[word-'a']++;
        }
        for (size_t i = 0; i < alphabet_t.size(); i++){
            if (alphabet_s[i]!=alphabet_t[i]){
                return false;
            }   
        }
        return true;
    }
};
// @lc code=end

