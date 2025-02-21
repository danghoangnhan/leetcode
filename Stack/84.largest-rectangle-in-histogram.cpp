/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int maxArea = 0;
        stack<int> stack;
        heights.push_back(0);

        for (int i = 0; i < heights.size(); ++i) {
            while (!stack.empty() && heights[i] < heights[stack.top()]) {
                int height = heights[stack.top()];
                stack.pop();
                int width = stack.empty() ? i : i - stack.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            stack.push(i);
        }
        return maxArea;
    }
};
// @lc code=end

