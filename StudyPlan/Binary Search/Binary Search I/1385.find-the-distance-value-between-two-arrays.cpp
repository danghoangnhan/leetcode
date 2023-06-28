#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode id=1385 lang=cpp
 *
 * [1385] Find the Distance Value Between Two Arrays
 */

// @lc code=start
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int result = 0;
        for (int i:arr1){
            int check=true;
            for(int j:arr2){
                if(abs(i-j)<=d){
                    check=false;
                    break;
                }
            }
            if (check){result++;}
            
        }
        return result;
        
    }
};
// @lc code=end

