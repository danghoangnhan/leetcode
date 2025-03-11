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
            int n1 = s1.size(), n2 = s2.size();
            if (n1 > n2) return false;  
            vector<int> countS1(26, 0), countWin(26, 0);
            
            for (char c: s1) {
                countS1[c - 'a']++;
            }
            
            for (int i = 0; i < n1; i++) {
                countWin[s2[i] - 'a']++;
            }
    
            int matchCount = 0;
            for (int i = 0; i < 26; i++) {
                if (countS1[i] == countWin[i]) {
                    matchCount++;
                }
            }
            
            if (matchCount == 26) return true;
            
            for (int i = n1; i < n2; i++) {
                int newChar = s2[i] - 'a';
                int oldChar = s2[i - n1] - 'a';
                
                if (countS1[oldChar] == countWin[oldChar]) {
                    matchCount--;
                }
                countWin[oldChar]--;
                if (countS1[oldChar] == countWin[oldChar]) {
                    matchCount++;
                }
                
                if (countS1[newChar] == countWin[newChar]) {
                    matchCount--;
                }
                countWin[newChar]++;
                if (countS1[newChar] == countWin[newChar]) {
                    matchCount++;
                } 
                if (matchCount == 26) return true;
            }
            return false;
        }
    };
// @lc code=end

