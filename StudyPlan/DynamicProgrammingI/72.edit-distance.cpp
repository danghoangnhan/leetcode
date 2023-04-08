/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
    int length[text1.length()+1][text2.length()+1];
	
    for (int i=0; i<=text1.length(); i++){
        length[i][text2.length()] = text1.length()-i;
    } 
	for (int i=0; i<=text2.length(); i++){
        length[text1.length()][i] = text2.length()-i;
    } 

	for (int i=text1.length()-1; i>=0; i--)
		for (int j=text2.length()-1; j>=0; j--)
			if (text1[i] == text2[j])
				length[i][j] = length[i+1][j+1];
			else
				length[i][j] = 1+min(length[i+1][j],min(length[i][j+1],length[i+1][j+1]));
	return length[0][0];
    }
    int minDistance(string word1, string word2) {
       int lcs = longestCommonSubsequence(word1,word2);
       return  lcs; 
    }
};
// @lc code=end

