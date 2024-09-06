/*
 * @lc app=leetcode id=2418 lang=cpp
 *
 * [2418] Sort the People
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> people;
        for (int i = 0; i < names.size(); ++i) {
            people.emplace_back(heights[i], names[i]);
        }

        sort(people.begin(), people.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first;
        });

        vector<string> sortedNames;
        for (const auto& p : people) {
            sortedNames.push_back(p.second);
        }
        return sortedNames;
    }
};
// @lc code=end

