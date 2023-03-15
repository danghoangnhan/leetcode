#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {

        if (n<=1){return n;}    
        
        vector<int> map(301);
        map[1]=1;
        map[0]=0;
        
        for (int i = 2; i <=n; i++){
            map[i] = map[i-1]+map[i-2];
        }
        
        return map[n];
    }
};
// @lc code=end

