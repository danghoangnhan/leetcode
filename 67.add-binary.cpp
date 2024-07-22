/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        
        int m = a.size();
        int n = b.size();
        string result;
        result.reserve(max(m, n) + 1);  // Reserve space for result

        int carry = 0;
        int i = m - 1;
        int j = n - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            
            if (i >= 0) {
                sum += a[i] - '0';  // Convert char to int
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';  // Convert char to int
                j--;
            }
            
            result.push_back(sum % 2 + '0');  // Append result bit
            carry = sum / 2;                  // Update carry
        }

        reverse(result.begin(), result.end());  // Reverse the result to get the correct order
        return result;
    }
};
// @lc code=end

