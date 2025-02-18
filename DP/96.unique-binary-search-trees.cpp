#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> trees(n+1,1);
        for (int i = 2; i <= n; i++){
            int currentVal = 0;
            for (int j= 1;j <= i; j++){
                currentVal += trees[j-1]*trees[i-j];
            }
            trees[i]=currentVal;
        }
        return trees[n];
    }
};
// @lc code=end

