/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
   int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (const string& token : tokens) {
            if (token.size() == 1 && !isdigit(token[0])) {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                switch (token[0]) {
                    case '+': stk.push(a + b); break;
                    case '-': stk.push(a - b); break;
                    case '*': stk.push(a * b); break;
                    case '/': stk.push(a / b); break;
                }
            } else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};

// @lc code=end

