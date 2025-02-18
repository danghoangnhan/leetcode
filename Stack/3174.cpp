#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        string result;
        stack<char> st;
        for(auto& element:s){
            if(element-'0'>=0 && element-'0'<=9){
                st.push(element);
            }else if (!st.empty()){
                st.pop();
            }
            else{
                result+= element;
            }
        return result;
        }
    }
};