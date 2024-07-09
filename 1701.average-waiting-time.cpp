/*
 * @lc app=leetcode id=1701 lang=cpp
 *
 * [1701] Average Waiting Time
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double result = 0;
        int currentTime = 1;
        for(auto customer: customers){
            int arrivalTime = customer[0];
            int processingTime = customer[1];
            if(currentTime < arrivalTime) {
                currentTime = arrivalTime;
            }
            currentTime += processingTime;
            result += currentTime  - arrivalTime;
        }
        return result / customers.size();
    }
};
// @lc code=end

