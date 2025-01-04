#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool canTransform(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        // Use prefix sum to efficiently track coverage
        vector<int> coverage(n + 1, 0);
        
        // For each query [l,r], add 1 at l and subtract 1 after r
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            coverage[left]++;
            coverage[right + 1]--; // Remove effect after right boundary
        }
        
        // Calculate actual coverage at each index using prefix sum
        for (int i = 1; i < n; i++) {
            coverage[i] += coverage[i - 1];
        }
        
        // Check if coverage is sufficient for each number
        for (int i = 0; i < n; i++) {
            if (coverage[i] < nums[i]) {
                return false;
            }
        }
        
        return true;
    }
};

// Test function
void runTest(vector<int> nums, vector<vector<int>> queries, bool expected) {
    Solution solution;
    bool result = solution.canTransform(nums, queries);
    cout << "Result: " << (result ? "true" : "false") 
         << ", Expected: " << (expected ? "true" : "false")
         << " -> " << (result == expected ? "PASSED" : "FAILED") << endl;
}

int main() {
    // Test cases
    runTest({1,0,1}, {{0,2}}, true);  // Example 1
    runTest({4,3,2,1}, {{1,3},{0,2}}, false);  // Example 2
    runTest({2,2,2}, {{0,2},{0,2}}, true);  // Exactly enough queries
    runTest({3,3,3}, {{0,1},{1,2},{0,2}}, true);  // Overlapping queries
    return 0;
}