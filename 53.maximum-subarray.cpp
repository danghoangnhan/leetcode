#include <vector>
#include <iostream>
#include <climits>
using namespace std;
/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maps[100000];
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        this->maps[0]=nums[0];
        for (int i = 1; i < nums.size(); i++){
            this->maps[i] = this->maps[i-1]+nums[i];
        }
        for (int i = 1; i < nums.size(); i++)
        {
            result = max(result,this->maps[i]);
            for (int j = 0; j<i; j++){
                int data = this->maps[i]-this->maps[j];
                cout<<data<<endl;
                result = max(result,data);
            }
        }
        return result;
    }
};
int main(){
    Solution solution;
    vector<int> data = {5,4,-1,7,8};
    cout << solution.maxSubArray(data) <<endl;
    for (int i = 0; i < data.size(); i++)
    {
        cout<<solution.maps[i]<<" ";
    }
    
    return 0;
}
// @lc code=end

