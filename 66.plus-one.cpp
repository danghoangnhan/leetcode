/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int index = digits.size()-1;
        while(index>=0 && carry>0){
            digits[index]   +=  carry;
            carry = digits[index]/10;
            digits[index] = digits[index]%10;
            index--;
        }
        if(carry>0){
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
// @lc code=end

