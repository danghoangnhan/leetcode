/*
 * @lc app=leetcode id=1718 lang=cpp
 *
 * [1718] Construct the Lexicographically Largest Valid Sequence
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> res;
    vector<bool> used;
    int n;
    
    bool backtrack(int index) {
        if (index == res.size()) return true; // If we filled all positions, return true

        if (res[index] != 0) return backtrack(index + 1); // Skip occupied positions

        // Try placing numbers from n to 1 (greedy approach)
        for (int num = n; num >= 1; --num) {
            if (used[num]) continue; // Skip already used numbers

            if (num == 1) { // 1 only needs one position
                res[index] = 1;
                used[num] = true;
                if (backtrack(index + 1)) return true;
                res[index] = 0;
                used[num] = false;
            } else {
                int secondPos = index + num;
                if (secondPos < res.size() && res[secondPos] == 0) { // Ensure valid placement
                    res[index] = res[secondPos] = num;
                    used[num] = true;
                    if (backtrack(index + 1)) return true;
                    // Backtrack
                    res[index] = res[secondPos] = 0;
                    used[num] = false;
                }
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        this->n = n;
        int size = 2 * n - 1;
        res.assign(size, 0);
        used.assign(n + 1, false);
        backtrack(0);
        return res;
    }
};
// @lc code=end

