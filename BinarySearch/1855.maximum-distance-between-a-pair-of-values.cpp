/*
 * @lc app=leetcode id=1855 lang=cpp
 *
 * [1855] Maximum Distance Between a Pair of Values
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            int j = upper_bound(begin(nums2), end(nums2), nums1[i], greater()) - begin(nums2);
            ans = max(ans, max(0, j - 1 - i));
        }
        return ans;
    }
};
// @lc code=end

