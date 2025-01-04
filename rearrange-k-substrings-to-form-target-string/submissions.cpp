#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.length();
        
        // Check if length is divisible by k
        if (n % k != 0) return false;
        
        // When k=1, strings must match exactly
        if (k == 1) return s == t;
        
        // Calculate substring length
        int subLen = n / k;
        
        vector<string> subs, subt;
        
        // Extract and sort substrings from both strings
        for (int i = 0; i < n; i += subLen) {
            string ss = s.substr(i, subLen);
            string st = t.substr(i, subLen);
            
            // sort(ss.begin(), ss.end());
            // sort(st.begin(), st.end());

            subs.push_back(ss);
            subt.push_back(st);
        }
        sort(subs.begin(), subs.end());
        sort(subt.begin(), subt.end());
        
        // for_each(subs.begin(), subs.end(), [](string i)
        // { cout << i << " "; });
        // cout << endl;
        
        // for_each(subt.begin(), subt.end(), [](string i)
        // { cout << i << " "; });
        // cout << endl;

        // Compare sorted vectors
        return subs == subt;
    }
};

// Test helper function
void runTest(const string& s, const string& t, int k, bool expected, int testNumber) {
    Solution solution;
    bool result = solution.isPossibleToRearrange(s, t, k);
    
    cout << "Test " << testNumber << ":\n";
    cout << "Input: s = \"" << s << "\", t = \"" << t << "\", k = " << k << "\n";
    cout << "Expected: " << (expected ? "true" : "false") << "\n";
    cout << "Got: " << (result ? "true" : "false") << "\n";
    
    if (result == expected) {
        cout << "✓ PASSED\n";
    } else {
        cout << "✗ FAILED\n";
    }
    cout << "-------------------\n";
}

int main() {
    runTest("abcd", "cdab", 2, true, 1);
    runTest("aabbcc", "bbaacc", 3, true, 2);
    runTest("aabbcc", "bbaacc", 2, false, 3);
    runTest("nc", "cn", 1, false, 4);
    runTest("a", "a", 1, true, 5);  // Single character
    runTest("aa", "aa", 2, true, 6); // Two identical characters    
    runTest("aaaa", "aaaa", 2, true, 7);
    runTest("abcdefgh", "efghabcd", 2, true, 8);
    
    runTest("abcd", "dcba", 4, true, 9);
    
    runTest("abc", "cba", 3, true, 10);
    
    runTest("abc", "cba", 2, false, 11);  // Length not divisible by k
    
    runTest("aabbccaabbcc", "ccaabbccaabb", 6, true, 12);
    
    runTest("xxyyzz", "zzyyxx", 3, true, 13);
    
    runTest("abcdefghijkl", "ghijklabcdef", 4, true, 14);
    
    runTest("aabb", "abba", 2, false, 15);

    runTest("jvdk", "vjdk", 2, false, 16);
    
    cout << "All tests completed!\n";
    return 0;
}