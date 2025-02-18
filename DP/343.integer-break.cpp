#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> mul(n+1,1);
        for (int i = 2; i <= n; i++){
            int limit = (i%2==0)?i/2:((i/2)+1);
            mul[i] = (i==n)?0:i;
            for (int j = 1; j <= limit; j++){
                mul[i] = max(mul[i],mul[j]*mul[i-j]);
            }
            
        }
        return mul[n];
    }
};
// @lc code=end

