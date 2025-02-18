#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long costNoReorder = 0;
        for (int i = 0; i < (int)arr.size(); i++) {
            costNoReorder += llabs(arr[i] - brr[i]);
        }

        vector<int> sortedArr = arr;
        vector<int> sortedBrr = brr;
        
        sort(sortedArr.begin(), sortedArr.end());
        sort(sortedBrr.begin(), sortedBrr.end());

        long long costSorted = 0;
        for (int i = 0; i < (int)arr.size(); i++) {
            costSorted += llabs(sortedArr[i] - sortedBrr[i]);
        }

        long long costReorder = k + costSorted;

        return min(costNoReorder, costReorder);        
    }
};