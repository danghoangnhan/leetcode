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
class Solution {
public:
    map<char, char> converter = {
        {'{', '}'},
        {'[', ']'},
        {'(', ')'}
    };
    bool isValid(string s) {
        stack<char> re;

        for (int i = 0; i < s.size(); i++)
        {
            if (converter.count(s.at(i))){re.push(s.at(i));}
            else
            {
                if (re.empty())return false;
                if (converter[re.top()] != s.at(i))return false;
                re.pop();     
            }
        }
        return re.empty();
    }
};
// @lc code=end