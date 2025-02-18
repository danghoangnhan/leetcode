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
    pair<int,int> checking(int startLeft,int startRight,string Pattern){
        if(Pattern.empty() ||Pattern.length()<1) return make_pair(0,0);
        int left=startLeft,right=startRight; 
        while (left>=0 && right <Pattern.size() && Pattern[left]==Pattern[right]){
            left--;
            right++;
        }
        return make_pair(left+1,right-1);
    }
    int getLength(pair<int,int>location){
        return location.second - location.first +1;
    }

    string longestPalindrome(string s) {
        if(s.empty() ||s.length()<1) return "";
        pair<int,int>result = make_pair(0,0);

        for(int i =0;i<s.size();i++){
            pair<int,int>even = checking(i,i,s);
            pair<int,int>odd = checking(i,i+1,s);
            
            if (getLength(result)<getLength(even)){
                result = even;
            }
            if (getLength(result)<getLength(odd)){
                result = odd;
            }
            // cout<<result.first<<" "<<result.second<<endl;
        }
        return s.substr(result.first,result.second-result.first+1);        
    }
};
// @lc code=end

