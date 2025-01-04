#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    long long minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        long long minSum = LLONG_MAX;
        bool found = false;
        
        vector<long long> prefixSums(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }
        
        // For each valid subarray length
        for (int size = l; size <= r; size++) {
            // Check all possible subarrays of current size
            for (int start = 0; start <= n - size; start++) {
                // Calculate subarray sum using prefix sums
                long long currSum = prefixSums[start + size] - prefixSums[start];
                
                // Update minimum sum if current sum is positive
                if (currSum > 0) {
                    minSum = min(minSum, currSum);
                    found = true;
                }
            }
        }      
        return found ? minSum : -1;
    }
};