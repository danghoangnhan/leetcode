/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<string> findRelativeRanks(vector<int>& score) {
    int n = score.size();
    vector<string> ranks(n);
    vector<pair<int, int>> scored_indices(n);

    for (int i = 0; i < n; ++i) {
        scored_indices[i] = {score[i], i};
    }

    // Sort the vector in descending order by score
    sort(scored_indices.begin(), scored_indices.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    });

    // Assign ranks based on the sorted scores
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            ranks[scored_indices[i].second] = "Gold Medal";
        } else if (i == 1) {
            ranks[scored_indices[i].second] = "Silver Medal";
        } else if (i == 2) {
            ranks[scored_indices[i].second] = "Bronze Medal";
        } else {
            ranks[scored_indices[i].second] = to_string(i + 1);
        }
    }
    return ranks;
}

};

// @lc code=end

