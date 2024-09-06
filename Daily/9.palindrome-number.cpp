#include<vector>
#include<string>
#include <algorithm>

using namespace std;
/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        string s1  = to_string(x);
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        return s1==s2;
    }
};
// @lc code=end

