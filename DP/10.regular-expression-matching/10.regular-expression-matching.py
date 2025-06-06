#
# @lc app=leetcode id=10 lang=python3
#
# [10] Regular Expression Matching
#

# @lc code=start


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        
        s_size: int = len(s)
        p_size: int = len(p)

        dp = [[False] * (p_size + 1) for _ in range(s_size + 1)]
        dp[0][0] = True


        for j in range(1, p_size + 1):
            if p[j - 1] == '*':
                dp[0][j] = dp[0][j - 2]

        for i in range(1, s_size + 1):
            for j in range(1, p_size + 1):
                if p[j - 1] == s[i - 1] or p[j - 1] == '.':
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j - 1] == '*':
                    dp[i][j] = dp[i][j - 2] or (dp[i - 1][j] and (s[i - 1] == p[j - 2] or p[j - 2] == '.'))

        return dp[s_size][p_size]
# @lc code=end

