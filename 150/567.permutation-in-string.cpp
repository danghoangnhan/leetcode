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
        for(auto& chacracter:s1){
            count[chacracter-'a']++;
        }
        for (int end = 0; end < s2.length(); end++) {
            maxCount = max(maxCount, count[s2[end] - 'a']);
            
            if (end - start + 1 - maxCount > k) {
                count[s2[start] - 'a']--;
                start++;
            }
            
            maxLength = max(maxLength, end - start + 1);
        }
        
        return false;
    }
};
// @lc code=end

