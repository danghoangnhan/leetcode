/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

// @lc code=start
class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        vector<int> result(n + 1, INT_MAX);
        result[1] = 0;

        for (int i = 2; i <= n; i++) {
            if(result[i] ==INT_MAX){
                result[i] = i;
            }
            for (int j = 2; i * j <= n; j++) {
                result[i * j] = min(result[i * j], result[i] + j);
            }
        }
        return result[n];
    }
};

// @lc code=end

