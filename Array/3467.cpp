#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n = nums.size();
        int odd =0;
        for(int i = 0; i < n; i++){
            if (nums[i]%2)
                odd++;
        }
        for(int i = n-1; i>=0; i--){
            if (odd>0){
                nums[i]=1;
                odd--;
                continue;
            }
            nums[i]=0;
        }

        return nums;
    }
};