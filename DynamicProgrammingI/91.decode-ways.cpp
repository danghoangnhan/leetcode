#include <vector>
#include <string>
#include <iostream>

using namespace std;
/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
    int isAphabetchar(char sample){
        int index = sample - '0';
        return index>=1 && index<=26;
    }
    int isAphabet(string sample){
        if (sample[0]=='0'){return 0;}
        int index = stoi(sample);
        return index>=1 && index<=26;
    }
    int numDecodings(string s) {
        vector<int>count(s.size(),0);
        if (s.size()==1){return isAphabet(s);}
        
        count[0]= isAphabetchar(s[0]);
        count[1]=isAphabet(s.substr(0,2));

        if (count[0] && isAphabetchar(s[1])){
                count[1] += 1;
        }

        for (int i = 2; i < s.size(); i++)
        {
            if(count[i-1] && isAphabetchar(s[i])){
                count[i] += count[i-1];
            }
            if (isAphabet(s.substr(i-1,2)) && count[i-2]){
                count[i] += count[i-2];
            }      
        }
        return count[s.size()-1];
    }
};

// @lc code=end

