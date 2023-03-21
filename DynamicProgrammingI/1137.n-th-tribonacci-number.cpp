/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        
        vector<int> map(301);
        
        map[2]=1;
        map[1]=1;
        map[0]=0;
        
        if (n<=1){return map[n];}    
        
        for (int i = 3; i <=n; i++){
            map[i] = map[i-1]+map[i-2]+map[i-3];
        }
        
        return map[n];
    }
};
// @lc code=end

