/*
 * @lc app=leetcode id=1910 lang=cpp
 *
 * [1910] Remove All Occurrences of a Substring
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
    string result;
    int partLen = part.length();

    for (char c : s) {
        result.push_back(c);

        if (result.size() >= partLen && result.substr(result.size() - partLen) == part) {
            result.erase(result.size() - partLen);
        }
    }
    return result;
    }
};
// @lc code=end

