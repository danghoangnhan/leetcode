class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        result = vector<int>(target+1,-1);
        result[0]=1;
        return dp(nums,target);
    }
    int dp(vector<int>& nums,int target){
        if(target<0)return 0;
        if(result[target]!=-1)return result[target];
        int ans =0;
        for(int num:nums){
            ans +=dp(nums,target-num);
        } 
        return result[target] = ans;
    }
private:
    vector<int>result;
};
