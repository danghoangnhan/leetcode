#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size()<2) return true;
        
        int n = nums.size();
        for(int i=0;i<n-1;i++)
            if((nums[i]+nums[i+1])%2==0)
                return false;

        return true;
    }
};