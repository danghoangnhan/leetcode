#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size()==0)return 0;
        int left =0,right = height.size()-1;
        int maxL = height[0];
        int maxR = height[height.size()-1];
        int result = 0;
        while (left<right)
        {
            if (maxL < maxR)
            {
                left +=1;
                maxL = max(maxL,height[left]);
                result += maxL - height[left];
            }
            else{
                right -=1;
                maxR = max(maxR,height[right]);
                result += maxR - height[right];
            }
            
        }
        return result;
    }
};
// @lc code=end

