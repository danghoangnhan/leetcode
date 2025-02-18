/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class FreqStack {
private:
    unordered_map<int, int> freq;           // tracks frequency of each value
    unordered_map<int, stack<int>> group;   // groups values by frequency
    int maxfreq;                            // tracks current maximum frequency
    
public:
    FreqStack() : maxfreq(0) {}
    
    void push(int val) {
        freq[val]++;
        group[freq[val]].push(val);
        maxfreq = max(maxfreq, freq[val]);
    }
    
    int pop() {
        int val = group[maxfreq].top();
        group[maxfreq].pop();
        freq[val]--;
        
        if (group[maxfreq].empty()) {
            maxfreq--;
        }
        
        return val;
    }
};


/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

