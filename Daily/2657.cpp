#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = B.size();
        vector<int> result(n,0);
        unordered_set<int> A_set;
        A_set.insert(A[0]);
        unordered_set<int> B_set;
        B_set.insert(B[0]);
        result[0] = (A_set.find(B[0])!=A_set.end() && B_set.find(A[0])!=B_set.end())? 1:0;
        for(int i=1;i<n;i++){
            A_set.insert(A[i]);
            B_set.insert(B[i]);
            result[i]=result[i-1] +(A_set.find(B[0])!=A_set.end() && B_set.find(A[0])!=B_set.end())? 1:0;
        }
        return result;
    }
};