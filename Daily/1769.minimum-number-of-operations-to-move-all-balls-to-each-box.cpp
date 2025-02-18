#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        const int n = boxes.length();
        vector<int> result(n);
        
        int ballCount = 0;
        int operations = 0;
        
        for (int i = 0; i < n; ++i) {
            result[i] = operations;
            ballCount += (boxes[i] == '1');
            operations += ballCount;
        }
        
        ballCount = 0;
        operations = 0;
        
        for (int i = n - 1; i >= 0; --i) {
            result[i] += operations;
            ballCount += (boxes[i] == '1');
            operations += ballCount;
        }
        return result;
    }
};
