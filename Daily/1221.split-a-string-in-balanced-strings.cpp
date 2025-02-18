/*
 * @lc app=leetcode id=1221 lang=cpp
 *
 * [1221] Split a String in Balanced Strings
 */

// @lc code=start
class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0;
        int count = 0;
        
        for (char c : s) {
            if (c == 'L') {
                balance++;
            } else if (c == 'R') {
                balance--;
            }
            
            if (balance == 0) {
                count++;
            }
        }
        
        return count;
    }
};
// @lc code=end

