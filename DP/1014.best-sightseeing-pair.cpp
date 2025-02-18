#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int minValue = INT_MIN;
        int maxValue = INT_MIN;
        for(int i=values.size()-2;i>=0;i--){
            minValue = max(values[i+1]-(i+1),minValue);
            maxValue = max(values[i]+i+minValue,maxValue);
        }
        return maxValue;
    }
};
// @lc code=end

