#include <iostream>
using namespace std;

class Solution {
public:
    int minChanges(int n, int k) {
        // Check if k has bits set to 1 where n has bits set to 0
        if ((n | k) != n) {
            return -1;
        }

        int changes = 0;
        
        // Iterate through each bit position
        while (n > 0 || k > 0) {
            int n_bit = n & 1;
            int k_bit = k & 1;
            
            // Check if we need to change a 1 bit in n to 0 to match k
            if (n_bit == 1 && k_bit == 0) {
                changes++;
            }
            
            // Right shift n and k to check the next bit
            n >>= 1;
            k >>= 1;
        }

        return changes;
    }
};