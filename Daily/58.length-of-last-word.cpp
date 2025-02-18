/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int num=0;
        bool space = false;
        for(auto& element:s){
            if(element==' '){
                space=true;
                continue;
            }
            else if(space){
                num=0;
                space=false;
            }
            num++;
        }
        return num;
    }
};
// @lc code=end

