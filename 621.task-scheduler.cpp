/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int max_freq = 0;
        int max_count = 0;

        // Count frequencies and find max frequency
        for (char task : tasks) {
            freq[task - 'A']++;
            if (freq[task - 'A'] > max_freq) {
                max_freq = freq[task - 'A'];
                max_count = 1;
            } else if (freq[task - 'A'] == max_freq) {
                max_count++;
            }
        }

        // Calculate the minimum number of intervals required
        int intervals = (max_freq - 1) * (n + 1) + max_count;

        // Return the maximum of intervals and the total number of tasks
        return max(intervals, static_cast<int>(tasks.size()));
    }
};// @lc code=end

