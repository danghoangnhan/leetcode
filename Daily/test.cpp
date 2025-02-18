#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        vector<pair<int, int>> zorvintakol(n);
        
        // Initialize the pairs with index and value
        for(int i = 0; i < n; i++) {
            zorvintakol[i] = {i, nums[i]};
        }
        
        // Try different orders of operations using backtracking
        int result = tryOperations(zorvintakol, k, op1, op2);
        return result;
    }
    int tryOperations(vector<pair<int, int>>& arr, int k, int op1, int op2) {
        int n = arr.size();
        int minSum = INT_MAX;
        
        // Function to calculate current sum
        auto getSum = [&]() {
            int sum = 0;
            for(const auto& p : arr) {
                sum += p.second;
            }
            return sum;
        };
        
        // Try all possible combinations
        vector<bool> usedOp1(n, false);
        vector<bool> usedOp2(n, false);
        
        // Try each operation on each number
        for(int i = 0; i < n; i++) {
            for(int op = 0; op < 2; op++) {
                if(op == 0 && op1 > 0 && !usedOp1[arr[i].first]) {
                    // Try division
                    int oldVal = arr[i].second;
                    arr[i].second = (arr[i].second + 1) / 2;
                    usedOp1[arr[i].first] = true;
                    op1--;
                    
                    minSum = min(minSum, tryOperations(arr, k, op1, op2));
                    
                    // Backtrack
                    arr[i].second = oldVal;
                    usedOp1[arr[i].first] = false;
                    op1++;
                }
                else if(op == 1 && op2 > 0 && !usedOp2[arr[i].first] && arr[i].second >= k) {
                    // Try subtraction
                    int oldVal = arr[i].second;
                    arr[i].second -= k;
                    usedOp2[arr[i].first] = true;
                    op2--;
                    
                    minSum = min(minSum, tryOperations(arr, k, op1, op2));
                    
                    // Backtrack
                    arr[i].second = oldVal;
                    usedOp2[arr[i].first] = false;
                    op2++;
                }
            }
        }
        
        // If we can't perform any more operations or haven't found a better sum
        if(minSum == INT_MAX) {
            minSum = getSum();
        }
        
        return minSum;
    }
};
// Test helper function
void runTest(vector<int> nums, int k, int op1, int op2, int expected, int testNumber) {
    Solution solution;
    
    // Print input
    cout << "Test " << testNumber << ":\n";
    cout << "Input:\n";
    cout << "nums = [";
    for(size_t i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if(i < nums.size() - 1) cout << ",";
    }
    cout << "], k = " << k << ", op1 = " << op1 << ", op2 = " << op2 << "\n";
    
    // Get result
    int result = solution.minArraySum(nums, k, op1, op2);
    
    // Print result and expected
    cout << "Expected: " << expected << "\n";
    cout << "Got: " << result << "\n";
    
    // Check if test passed
    if(result == expected) {
        cout << "✓ PASSED\n";
    } else {
        cout << "✗ FAILED\n";
    }
    cout << "-------------------\n";
}

int main() {
    runTest({2,8,3,19,3}, 3, 1, 1, 23, 1);
    
    runTest({2,4,3}, 3, 2, 1, 3, 2);
    
    runTest({10}, 5, 1, 1, 3, 3);
    
    runTest({1,2,3}, 5, 0, 0, 6, 4);
    
    runTest({8,16,32}, 10, 3, 0, 14, 5);
    
    runTest({10,10,10}, 5, 0, 3, 15, 6);
    
    runTest({100,100,100}, 50, 2, 2, 150, 7);
    
    runTest({4,4,4}, 0, 2, 2, 6, 8);
    
    runTest({2,2,2}, 5, 1, 3, 3, 9);
    
    runTest({20,15,10,5}, 5, 2, 2, 20, 10);
    
    vector<int> largeArray(50, 10);
    runTest(largeArray, 5, 25, 25, 250, 11);
    
    runTest({5,5}, 2, 5, 5, 4, 12);
    
    runTest({7,7,7}, 2, 3, 0, 12, 13);
    
    runTest({0,0,10}, 5, 1, 1, 0, 14);
    
    vector<int> maxTest = {100000, 100000};
    runTest(maxTest, 100000, 2, 2, 50000, 15);
    
    cout << "All tests completed!\n";
    return 0;
}