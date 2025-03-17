/*
 * @lc app=leetcode id=2594 lang=cpp
 *
 * [2594] Minimum Time to Repair Cars
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool canRepairInTime(const vector<int>& ranks, int cars, long long time) {
        long long total_cars = 0;
        for (const auto& rank : ranks) {
            total_cars += static_cast<long long>(std::sqrt(time / rank));
            if (total_cars >= cars) {
                return true;
            }
        }
        return total_cars >= cars;
    }

    long long repairCars(std::vector<int>& ranks, int cars) {
        long long left = 0;
        long long min_rank = *std::min_element(ranks.begin(), ranks.end());
        long long right = static_cast<long long>(min_rank) * cars * cars;
        long long answer = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canRepairInTime(ranks, cars, mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
};
// @lc code=end

