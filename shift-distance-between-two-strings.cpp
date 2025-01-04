#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        int n = s.length();
        long long totalCost = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == t[i]) continue;
            
            char from = s[i], to = t[i];
            long long forwardCost = 0, backwardCost = 0;
            
            char curr = from;
            while(curr != to) {
                curr++;
                if(curr > 'z') curr = 'a';
                forwardCost += nextCost[curr - 'a'];
            }
            
            curr = from;
            while(curr != to) {
                curr--;
                if(curr < 'a') curr = 'z';
                backwardCost += previousCost[curr - 'a'];
            }
            cout<<forwardCost<<" "<<backwardCost<<endl;
            totalCost += min(forwardCost, backwardCost);
        }
        
        return totalCost;
    }
};

void runTest(string s, string t, vector<int>& nextCost, vector<int>& previousCost, long long expected) {
    Solution sol;
    long long result = sol.shiftDistance(s, t, nextCost, previousCost);
    cout << "Test: s = \"" << s << "\", t = \"" << t << "\"" << endl;
    cout << "Expected: " << expected << ", Got: " << result << endl;
    assert(result == expected);
    cout << "Test Passed!\n\n";
}

int main() {
    // Test Case 1: Example from the problem
    {
        string s = "abab";
        string t = "baba";
        vector<int> nextCost(26, 0);
        vector<int> previousCost(26, 100);
        nextCost[0] = 100;  // cost for 'a'
        previousCost[0] = 1;  // cost for 'b'
        previousCost[1] = 100;
        runTest(s, t, nextCost, previousCost, 2);
    }

    // Test Case 2: Second example from the problem
    {
        string s = "leet";
        string t = "code";
        vector<int> nextCost(26, 1);
        vector<int> previousCost(26, 1);
        runTest(s, t, nextCost, previousCost, 31);
    }

    // Test Case 3: No change needed
    {
        string s = "hello";
        string t = "hello";
        vector<int> nextCost(26, 1);
        vector<int> previousCost(26, 1);
        runTest(s, t, nextCost, previousCost, 0);
    }

    // Test Case 4: Single character change
    {
        string s = "a";
        string t = "z";
        vector<int> nextCost(26, 2);
        vector<int> previousCost(26, 1);
        runTest(s, t, nextCost, previousCost, 1);  // should use backward shift
    }

    // Test Case 5: All characters need to be changed
    {
        string s = "aaaa";
        string t = "zzzz";
        vector<int> nextCost(26, 2);
        vector<int> previousCost(26, 1);
        runTest(s, t, nextCost, previousCost, 4);  // should use backward shift 4 times
    }

    // Test Case 6: Mixed costs
    {
        string s = "abc";
        string t = "def";
        vector<int> nextCost(26, 10);
        vector<int> previousCost(26, 5);
        for(int i = 0; i < 3; i++) {
            nextCost[i] = 1;  // make forward movement cheaper for first 3 letters
        }
        runTest(s, t, nextCost, previousCost, 3);  // should use forward shifts
    }

    cout << "All tests passed!" << endl;
    return 0;
}