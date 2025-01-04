#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    // Helper function to simulate process from a given start position and direction
    bool simulate(vector<int>& nums, int start, bool goRight) {

        int n = nums.size();
        vector<int> arr = nums;
        int curr = start;
        
        // Continue process until we go out of bounds
        while (curr >= 0 && curr < n) {
            if (arr[curr] == 0) {
                // Move in current direction
                curr = goRight ? curr + 1 : curr - 1;
            } else {
                // Decrement current value
                arr[curr]--;
                // Reverse direction
                goRight = !goRight;
                // Move in new direction
                curr = goRight ? curr + 1 : curr - 1;
            }
        }
        
        // Check if all elements are zero
        for (int x : arr) {
            if (x != 0) return false;
        }
        return true;
    }
    
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int validCount = 0;
        
        // Try each possible starting position
        for (int i = 0; i < n; i++) {
            // Only consider positions that start with 0
            if (nums[i] == 0) {
                // Try both directions
                if (simulate(nums, i, true))
                    validCount++;
                if (simulate(nums, i, false))
                    validCount++;
            }
        }
        
        return validCount;
    }
};