#include<math.h>
using namespace std;
/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int result = sqrt(num);
        return result*result == num;
    }
};
// @lc code=end

