#include <map>
#include <vector>
#include <math>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
public:
    map<int,int> frequency;
    int profit(int number){
        return  frequency[number] - (frequency[number+1]+frequency[number-1]);
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int>mapping;
        int result =-1;
        for (int num:nums){
            if (frequency.count(num)){
                frequency[num]+=num;
            }
            else{
                mapping.push_back(num);
                frequency[num]=num;
            }
        }
        sort(mapping.begin(), mapping.end());

        for (int startIndex=0;startIndex<mapping.size();startIndex++){
            int currentSum = frequency[mapping[startIndex]];
            int previous = mapping[startIndex];
            for (int next = startIndex+1; next < mapping.size(); next++){
                if (abs(mapping[next] - previous)==1){continue;}
                
                currentSum += frequency[mapping[next]];
                previous = mapping[next];
            }
            result = max(result,currentSum);
        }
        return result;
    }
};
// @lc code=end

