/*
 * @lc app=leetcode id=1937 lang=cpp
 *
 * [1937] Maximum Number of Points with Cost
 */

// @lc code=start
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<long long> dp(n);
        
        // Initialize dp with the first row
        for (int j = 0; j < n; j++) {
            dp[j] = points[0][j];
        }
        
        for (int i = 1; i < m; i++) {
            vector<long long> left_max(n), right_max(n), new_dp(n);
            
            // Compute left_max
            left_max[0] = dp[0];
            for (int j = 1; j < n; j++) {
                left_max[j] = max(left_max[j-1] - 1, dp[j]);
            }
            
            // Compute right_max
            right_max[n-1] = dp[n-1];
            for (int j = n-2; j >= 0; j--) {
                right_max[j] = max(right_max[j+1] - 1, dp[j]);
            }
            
            // Compute new_dp
            for (int j = 0; j < n; j++) {
                new_dp[j] = points[i][j] + max(left_max[j], right_max[j]);
            }
            
            dp = new_dp;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end

