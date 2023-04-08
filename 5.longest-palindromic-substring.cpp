#include <string>
using namespace std;
/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    int checking(int startLeft,int startRight,string Pattern){
        if(Pattern.empty() ||Pattern.length()<1) return 0;
        int left=startLeft,right=startRight; 
        while (left>=0 && right <Pattern.size() && Pattern[left]==Pattern[right]){
            left--;
            right++;
        }
        return right - left +1;
    }

    string longestPalindrome(string s) {
        if(s.empty() ||s.length()<1) return "";
        int start=0,end=0;
        for(int i =0;i<s.size();i++){
            int len = max(checking(i,i,s),checking(i,i+1,s));
            if (len>end-start){
                start = i- ((len-1)/2);
                end = i+(len/2);
            }
            
        }
        return s.substr(start,end - start +1);        
    }
};
// @lc code=end

