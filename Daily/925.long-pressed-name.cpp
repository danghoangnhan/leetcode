/*
 * @lc app=leetcode id=925 lang=cpp
 *
 * [925] Long Pressed Name
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int name_index =0;
        int typed_index = 0;
        while(typed_index < typed.size()){
            if(name[name_index]==typed[typed_index]){
                name_index++;
                typed_index++;
            }
            else if( name_index > 0  && name[name_index-1]==typed[typed_index]){
                typed_index++;
            }
            else{
                return false;
            }
        }
        return name_index==name.size();
    }
};
// @lc code=end

