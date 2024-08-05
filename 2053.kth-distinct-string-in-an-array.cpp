/*
 * @lc app=leetcode id=2053 lang=cpp
 *
 * [2053] Kth Distinct String in an Array
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
string kthDistinct(vector<string>& arr, int k) {
    unordered_map<string, int> frequency;
    vector<string> distinctStrings;

    // Step 1: Count the occurrences of each string
    for (const string& str : arr) {
        frequency[str]++;
    }
    // Step 2: Collect distinct strings in their order of appearance
    for (const string& str : arr) {
        if (frequency[str] == 1) {
            distinctStrings.push_back(str);
        }
    }
    // Step 3: Check if we have enough distinct strings and return the kth one
    return (k > distinctStrings.size()?"":distinctStrings[k - 1]);
}
};
// @lc code=end

