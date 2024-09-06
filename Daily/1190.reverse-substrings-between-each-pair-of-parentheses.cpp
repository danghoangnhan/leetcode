/*
 * @lc app=leetcode id=1190 lang=cpp
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stack;
        for (char ch : s) {
            if (ch == ')') {
                string temp;
                while (!stack.empty() && stack.top() != "(") {
                    temp = stack.top() + temp;
                    stack.pop();
                }
                stack.pop();
                reverse(temp.begin(), temp.end());
                stack.push(temp);
            } else {
                stack.push(string(1, ch));
            }
        }
        
        string result;
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        return result;
    }
};

// @lc code=end

