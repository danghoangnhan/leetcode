/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

  vector<int> sortArray(vector<int>& nums) {
    function<void(int, int)> quickSort = [&](int l, int r) {
      if (l >= r) return;      
      int i = l;
      int j = r;
      int p = nums[l + rand() % (r - l + 1)];
      while (i <= j) {
        while (nums[i] < p) ++i;
        while (nums[j] > p) --j;
        if (i <= j)
          swap(nums[i++], nums[j--]);
      }
      quickSort(l, j);
      quickSort(i, r);
    };
    quickSort(0, nums.size() - 1);
    return nums;
  }
};
// @lc code=end

