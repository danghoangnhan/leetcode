/*
 * @lc app=leetcode id=10 lang=golang
 *
 * [10] Regular Expression Matching
 */
// @lc code=start
func isMatch(s string, p string) bool {
    
	s_size := len(s)
	p_size := len(p)

	dp := make([][]bool, s_size+1)
	for i := range dp {
		dp[i] = make([]bool, p_size+1)
	}
	
	dp[0][0] = true
	for j := 1; j <= p_size; j++ {
		if p[j-1] == '*' {
			dp[0][j] = dp[0][j-2]
		}
	}
	
	for i := 1; i <= s_size; i++ {	
		for j := 1; j <= p_size; j++ {
			if p[j-1] == s[i-1] || p[j-1] == '.' {
				dp[i][j] = dp[i-1][j-1]
			} else if p[j-1] == '*' {
				dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'))
			}
		}
	}
	return dp[s_size][p_size]
}
// @lc code=end

