/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
public:
    int caculates(int number){
        int result = 0;
        for (int i = 3; i <= number; i++)
        {
            result += number-i+1;
        }
        cout<<"reward:"<<result<<endl;
        return result;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size()<3){return 0;}
        bool check = false;
        int start =0;
        int result =0;
        for (int i = 2; i < nums.size(); i++){
            bool compare = nums[i]-nums[i-1]==nums[start+1]-nums[start]; 
            if (compare){
                check = true;
            }
            else{
                if (check){
                    cout<<start<<" "<<i<<endl;
                    result +=caculates(i-start+1);
                    check = false;
                }
                start = i;
            }
            if (i==nums.size()-1){
                cout<<start<<" "<<i<<endl;
                result +=caculates(i-start+1);
            }
        }
        return result;
    }
        
};
// @lc code=end

