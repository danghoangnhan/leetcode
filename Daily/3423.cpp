#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
    int n = nums.size();
    int max_diff = 0;

    for(int i = 0; i < n; i++)
        max_diff = max(max_diff, abs(nums[i] - nums[(i + 1) % n]));
    
    return max_diff;
    }
};