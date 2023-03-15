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
        if (n<=2){    return n;}
        vector<int> steps;
        steps[0]=0;
        steps[1]=1;
        steps[2]=2;
        for (int i = 3; i < n+1; i++)
        {
            steps[i]=steps[i-1];
            if (i%2==0){steps[i]++;}
            
        }
        
        
    }
};
// @lc code=end

