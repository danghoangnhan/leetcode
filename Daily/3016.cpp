#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> frequency(26, 0);
        
        // Count frequency of each letter
        for (char c : word) {
            frequency[c - 'a']++;
        }
        
        // Sort frequencies in descending order
        sort(frequency.rbegin(), frequency.rend());
        
        int totalPushes = 0;
        
        // Assign letters to keys and calculate pushes
        for (int i = 0; i < 26; i++) {
            if (frequency[i] == 0) break;
            
            // Calculate number of pushes for this letter
            // i / 8 gives the number of times we've filled all 8 keys
            // So (i / 8) + 1 gives the number of pushes needed for this position
            totalPushes += frequency[i] * ((i / 8) + 1);
        }
        return totalPushes;
    }
};