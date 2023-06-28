#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=1491 lang=cpp
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
 */

// @lc code=start
class Solution {
public:
    double average(vector<int>& salary) {
        int maxValue = salary[0],minValue = salary[0],count=0;
        double result=0;
        for(int value:salary){
            maxValue = max(maxValue,value);
            minValue = min(minValue,value);
        }
        for(int value:salary){
            if(value!=minValue && value!=maxValue){
                count++;
                result+=value;
            }
        }
        return double(result/count);
    }
};
// @lc code=end

