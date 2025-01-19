#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int sum =0;
        for(auto& element:derived){
            sum ^=element;
        }
        return sum==0;
    }
};