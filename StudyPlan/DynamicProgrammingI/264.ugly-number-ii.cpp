#include <vector>
#include <iostream>
#include <set>
#include<queue>
using namespace std;
/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long int>base = {2,3,5};
        set<long long int> visited;
        priority_queue<long long int, vector<long long int>, greater<long long int> > my_min_heap;
        my_min_heap.emplace(1);
        long long int result =1;
        
        for (long long int count =0;count<n;count++){
            for (int i = 0; i < base.size(); i++){
                long long int newValue =  my_min_heap.top()*base[i];
                if (!visited.count(newValue)){
                    my_min_heap.emplace(newValue);
                    visited.insert(newValue);
                }
            }
            result = my_min_heap.top();
            my_min_heap.pop();
        } 
        return result;
    }
};

// @lc code=end

