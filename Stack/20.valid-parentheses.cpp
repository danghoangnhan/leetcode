#include <string>
#include <stack>
#include <map>
using namespace std;
/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    unordered_map<char, char> converter = {
        {'{', '}'},
        {'[', ']'},
        {'(', ')'}
    };
    bool isValid(string s) {
        stack<char> re;
        int n = s.size();
        for (int i = 0; i < n; i++){
            if (converter.count(s.at(i))){
                re.push(s.at(i));
                continue;
            }
            else{
                if (re.empty())return false;
                if (converter[re.top()] != s.at(i))return false;
                re.pop();     
            }
        }
        return re.empty();
    }
};
// @lc code=end