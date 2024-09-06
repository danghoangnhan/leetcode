/*
 * @lc app=leetcode id=1508 lang=cpp
 *
 * [1508] Range Sum of Sorted Subarray Sums
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> subarraySums;
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        
        // Generate all subarray sums
        for (int i = 0; i < n; ++i) {
            long long currentSum = 0;
            for (int j = i; j < n; ++j) {
                currentSum += nums[j];
                minHeap.push(currentSum);
            }
        }
        
        // Extract the sorted sums
        vector<long long> sortedSums;
        while (!minHeap.empty()) {
            sortedSums.push_back(minHeap.top());
            minHeap.pop();
        }
        
        // Compute the sum from index left to right
        long long totalSum = 0;
        for (int i = left - 1; i < right; ++i) {
            totalSum = (totalSum + sortedSums[i]) % MOD;
        }
        
        return totalSum;
    }
};

// @lc code=end

