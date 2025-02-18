/*
 * @lc app=leetcode id=2116 lang=cpp
 *
 * [2116] Check if a Parentheses String Can Be Valid
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int left =0,right =s.size();
        while(left<=right){
            if(s[left]==s[right]){
                left=right;
            }
            
            right++;
        }
        return true;        
    }
};
// @lc code=end

