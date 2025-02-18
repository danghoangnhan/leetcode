#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int frequency[101] = {0};  
        
        int maxFreq = 0;
        for(int num : nums) {
            frequency[num]++;
            maxFreq = max(maxFreq, frequency[num]);
        }
        
        int result = 0;
        for(int i = 0; i <= 100; i++) {
            if(frequency[i] == maxFreq) {
                result += maxFreq;
            }
        }
        return result;
    }
};