/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for (char c : t) map[c]++;
        
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        
        while (end < s.size()) {
            if (map[s[end++]]-- > 0) counter--;
            
            while (counter == 0) {
                if (end - begin < d) d = end - (head = begin);
                if (map[s[begin++]]++ == 0) counter++;
            }
        }
        
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};
// @lc code=end

