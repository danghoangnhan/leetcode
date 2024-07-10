/*
 * @lc app=leetcode id=1598 lang=cpp
 *
 * [1598] Crawler Log Folder
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (const string& log : logs) {
            if (log == "../") {
                if (depth > 0) depth--;
            } else if (log != "./") {
                depth++;
            }
        }
        return depth;
    }
};

// @lc code=end

