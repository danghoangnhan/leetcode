/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> check_list;
        for(auto& email:emails){
            vector<string> names = split(email,'@');

        }
        return check_list.size();
    }
};
// @lc code=end

