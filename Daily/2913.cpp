#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int result =0,sub=0;
        int seen[101] ={0};
        vector<int>prefixSum(nums.size(),1);    
        for(int i=1;i<nums.size();i++){
            prefixSum[i] += prefixSum[i-1];
            if(!seen[nums[i]]){
                seen[nums[i]]++;
                prefixSum[i]++;
            }
        }
        for(int i=0;i<nums.size();i++){
            result +=prefixSum[i]*prefixSum[i];
            result +=(prefixSum[nums.size()-1] -  prefixSum[i])*(prefixSum[nums.size()-1] -  prefixSum[i]);
        }

        return result;
    }
};