#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 */

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int hight = arr.size()-1;
        while(hight>low){
            int mid = (hight+low)/2;
            if (arr[mid] < arr[mid+1])
            {
                low =mid+1;
            }
            else{
                hight= mid;
            }
        }
        return low;
    }
};
// @lc code=end

