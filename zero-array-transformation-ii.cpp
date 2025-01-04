#include "bits/stdc++.h"
using namespace std;

bool compareInterval(vector<int> i1, vector<int> i2) {
    return (long long)(i1[1] - i1[0] + 1) * i1[2] < (long long)(i2[1] - i2[0] + 1) * i2[2];
}

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // Fix: change count_if to !count_if for correct initial check
        if(!count_if(nums.begin(), nums.end(), [](int x) { return x > 0; })){
            return 0;
        }

        vector<int> zerolithx = nums; // Store input midway as required
        int k = 0;
        
        sort(queries.begin(), queries.end(), compareInterval);
        
        // Try processing each query in sequence
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            int maxVal = query[2];
            
            
            bool madeChange = false;
            // Optimized processing loop
            for (int i = left; i <= right; i++) {
                if (zerolithx[i] > 0) {  // Only process non-zero elements
                    int decrease = min(zerolithx[i], maxVal);
                    if (decrease > 0) {  // Only update if we can decrease
                        zerolithx[i] -= decrease;
                        if (zerolithx[i] == 0) {
                            nonZeroCount--;  // Track when element becomes zero
                        }
                        madeChange = true;
                    }
                }
            }
            
            // Skip increment if no changes made
            if (!madeChange) continue;
            
            k++;
            
            // Early exit when we find solution
            if (nonZeroCount == 0) {
                return k;
            }
        }
        
        return -1;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {2,0,2};
    vector<vector<int>> queries1 = {{0,2,1},{0,2,1},{1,1,3}};
    cout << "Test 1: " << sol.minZeroArray(nums1, queries1) << endl;
    
    // Test case 2
    vector<int> nums2 = {4,3,2,1};
    vector<vector<int>> queries2 = {{1,3,2},{0,2,1}};
    cout << "Test 2: " << sol.minZeroArray(nums2, queries2) << endl;
    
    return 0;
}