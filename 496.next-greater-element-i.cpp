/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> next_greater;
        stack<int> st;
    
        for (int num : nums2) {
            while (!st.empty() && num > st.top()) {
                next_greater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
    
        while (!st.empty()) {
            next_greater[st.top()] = -1;
            st.pop();
        }
    
        vector<int> result;
        result.reserve(nums1.size());
        for (int x : nums1) {
            result.push_back(next_greater[x]);
        }
    return result;
    }
};
// @lc code=end

