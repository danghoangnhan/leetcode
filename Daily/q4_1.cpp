#include "bits/stdc++.h"
using namespace std;

class Solution {
public:

long long sumSubarrayMinsUpToK(const vector<int>& arr, int k) {
    int n = (int)arr.size();
    vector<int> left(n), right(n);

    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        long long L = i - left[i];   // extension to the left
        long long R = right[i] - i;  // extension to the right
        long long maxLen = L + R - 1;  // max subarray size around i
        long long m = min((long long)k, maxLen);

        if (m <= 0) continue;

        long long c1 = min(m, R - 1);
        long long seg1 = c1 * L;

        long long c2 = m - c1;
        long long seg2 = 0;
        if (c2 > 0) {
            long long sum_j = c2 * (c2 + 1) / 2;
            seg2 = c2 * (L + R - c1) - sum_j;
        }
        long long countValid = seg1 + seg2;
        answer += arr[i] * countValid;
    }
    return answer;
}

long long sumSubarrayMaxUpToK(const vector<int>& arr, int k) {
    int n = (int)arr.size();
}
};
