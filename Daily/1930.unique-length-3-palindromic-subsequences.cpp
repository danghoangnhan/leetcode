/*
 * @lc app=leetcode id=1930 lang=cpp
 *
 * [1930] Unique Length-3 Palindromic Subsequences
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int result = 0, length = s.size();
        vector<int> left(26, length);
        vector<int> right(26, -1);
        
        for(int i = 0; i < length; i++) {
            if(left[s[i]-'a'] == length) {
                left[s[i]-'a'] = i;
            }
            right[s[i]-'a']=i;
        }
        for(int i = 0; i < 26; i++) {

            unordered_set<char> check;
            for(int j = left[i] + 1; j < right[i]; j++) {
                    check.insert(s[j]);
                }
            result +=check.size();
        }
        return result;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();// @lc code=end

