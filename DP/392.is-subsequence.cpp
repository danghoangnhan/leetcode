/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

    int length[text1.size()+1][text2.size()+1];
	for (int i=0; i<=text1.size(); i++) length[i][0] = 0;
	for (int j=0; j<=text2.size(); j++) length[0][j] = 0;

	for (int i=1; i<=text1.size(); i++)
		for (int j=1; j<=text2.size(); j++)
			if (text1[i-1] == text2[j-1])
				length[i][j] = length[i-1][j-1] + 1;
			else
				length[i][j] = max(length[i-1][j],length[i][j-1]);
	return length[text1.size()][text2.size()];
    }
    bool isSubsequence(string s, string t) {
        return longestCommonSubsequence(s,t)==s.size();    
    }
};
// @lc code=end

