/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> stack;
        map<string, int> current;
        int n = formula.size();
        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                stack.push(current);
                current.clear();
                i++;
            } else if (formula[i] == ')') {
                // Process the closing parenthesis
                int i_start = ++i;
                while (i < n && isdigit(formula[i])) i++;
                int multiplicity = (i > i_start) ? stoi(formula.substr(i_start, i - i_start)) : 1;
                if (!stack.empty()) {
                    map<string, int> temp = current;
                    current = stack.top();
                    stack.pop();
                    for (auto &pair : temp) {
                        current[pair.first] += pair.second * multiplicity;
                    }
                }
            } else {
                int i_start = i++;
                while (i < n && islower(formula[i])) i++;
                string atom = formula.substr(i_start, i - i_start);
                i_start = i;
                while (i < n && isdigit(formula[i])) i++;
                int count = (i > i_start) ? stoi(formula.substr(i_start, i - i_start)) : 1;
                current[atom] += count;
            }
        }

        // Format the result string
        string result;
        for (const auto &pair : current) {
            result += pair.first;
            if (pair.second > 1) {
                result += to_string(pair.second);
            }
        }

        return result;
    }
};
// @lc code=end

