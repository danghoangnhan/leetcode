/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxScore(string s) {
        vector<int> zeros(s.size(),0);
        int result = 0;
        int length = s.size();

        for(int i=0;i<length;i++){
            if(i>0){
                zeros[i]=zeros[i-1];
            }
            if(s[i]=='0'){
                zeros[i]++;
            }
        }
        for(int i=0;i<length-1;i++){
            int current = zeros[i]+((length-i-1) - (zeros[length-1]-zeros[i]));
            result = max(current,result);
        }
        return result;
    }
};
// @lc code=end

