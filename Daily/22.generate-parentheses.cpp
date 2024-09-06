/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisRecursive(n, n, "", result);
        return result;
    }
void generateParenthesisRecursive(
        int left,
        int right,
        string current,
        vector<string>& result) {

        if (left == 0 && right == 0) {
            result.push_back(current);
            return;
        }

        if (left > 0) {
            generateParenthesisRecursive(left - 1, right, current + "(", result);
        }

        if (right > left) {
            generateParenthesisRecursive(left, right - 1, current + ")", result);
        }
    }
};
// @lc code=end

