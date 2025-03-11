#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleToRearrange(const string& s, const string& t, int k) {
        int n = s.size();
        
        if (n % k != 0) return false;
        
        if (k == 1) return s == t;
        
        int subLen = n / k;
        
        unordered_map<string, int> freqS, freqT;
        freqS.reserve(k);
        freqT.reserve(k);
        
        for (int i = 0; i < n; i += subLen) {
            string subS = s.substr(i, subLen);
            freqS[subS]++;
        }
        
        for (int i = 0; i < n; i += subLen) {
            string subT = t.substr(i, subLen);
            freqT[subT]++;
        }
        return freqS == freqT;
    }
};