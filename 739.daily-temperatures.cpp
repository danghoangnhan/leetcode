/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> stack;

    for (int i = 0; i < n; ++i) {
        while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
            int prev_index = stack.top();
            stack.pop();
            answer[prev_index] = i - prev_index;
        }
        stack.push(i);
    }
    return answer;
    }
};
// @lc code=end

