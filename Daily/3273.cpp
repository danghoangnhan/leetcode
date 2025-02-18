#include "bits/stdc++.h"
using namespace std;

class Solution {
        public:
        long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        vector<int> A(damage.size());
        for (int i = 0; i < damage.size(); ++i) {
            health[i] = (health[i] + power - 1) / power;
            A[i] = i;
        }
        sort(A.begin(), A.end(), [&](int i, int j) { 
            return health[i] * damage[j] < health[j] * damage[i];
        });

        long long res = 0, t = 0;
        for (int i : A) {
            res += damage[i] * (t += health[i]);
        }
        return res;
    }
};