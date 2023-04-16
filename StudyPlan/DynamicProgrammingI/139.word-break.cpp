#include<string>
#include<vector>
#include<unordered_set>
#include<iostream>

using namespace std;

/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */


// @lc code=start
class Solution {
public:
    vector<bool> dp;
    Solution(){
        for (int i = 0; i <=300; i++){
            dp.push_back(false);
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        for(int end=1;end<=s.length();end++){
            for(int start = end-1 ; start>=0;start--){
                string prefix = s.substr(start,end-start);
                if(dict.count(prefix)){
                    if (start==0 || dp[start-1])
                    {
                        dp[end-1] = true;
                        break;
                    }
                    
                }
            }
        }
        return dp[s.length()-1];        
    }       
};
// @lc code=end

