/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);
        stack<double> stack;
        
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }

        sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        for (const auto& car : cars) {
            if (stack.empty() || car.second > stack.top()) {
                stack.push(car.second);
            }
        }
        return stack.size();
    }
};
// @lc code=end

