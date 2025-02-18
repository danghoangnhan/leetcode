/*
 * @lc app=leetcode id=2381 lang=cpp
 *
 * [2381] Shifting Letters II
 */

// @lc code=start
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<long long> diff(n + 1, 0);

        for(vector<int>& shift:shifts){
            int direction=shift[2] ? 1 : -1;
            diff[shift[0]]+=direction;
            diff[shift[1]+1]-=direction;
        }
        int currentShift = 0;
        for(int i = 0;i<n;i++){
            currentShift+=diff[i];
            int totalShift = ((s[i] - 'a' + currentShift) % 26 + 26) % 26;
            s[i] = 'a' + totalShift;
        }
        return s;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
// @lc code=end

