#include <map>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() - 1;
        vector<int>result;
        while (hi > lo) {
            int currentSum = numbers[lo]+numbers[hi];

            if (currentSum>target){hi--;}
            else if  (currentSum<target){lo++;}
            else {
                result.push_back(lo+1);
                result.push_back(hi+1);
                break;
            }
        }
        return result;
    }
};
// @lc code=end

