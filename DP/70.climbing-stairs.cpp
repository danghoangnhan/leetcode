#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int ways[302];
        if(n <=2){return n;}
        ways[0]=0;
        ways[1]=1;
        ways[2]=2;
        for(int i=3;i<=n;i++){
            ways[i]=ways[i-1]+ways[i-2];
        }
        return ways[n];
    }
};
// @lc code=end

