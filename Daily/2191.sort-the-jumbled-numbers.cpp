/*
 * @lc app=leetcode id=2191 lang=cpp
 *
 * [2191] Sort the Jumbled Numbers
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int transform(int num, const vector<int>& mapper, unordered_map<int, int>& checked) {
        if (checked.find(num) != checked.end()) return checked[num];

        int result = 0;
        int place = 1;
        int original_num = num;

        // Handle the special case where num is 0
        if (num == 0) {
            checked[num] = mapper[0];
            return mapper[0];
        }

        // Transform the number using the mapper
        while (num != 0) {
            result += mapper[num % 10] * place;
            num /= 10;
            place *= 10;
        }

        checked[original_num] = result;
        return result;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> checked;

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return transform(a, mapping, checked) < transform(b, mapping, checked);
        });
        return nums;
    }
};

// @lc code=end

