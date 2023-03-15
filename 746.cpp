class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int ways[cost.size()+1];
        ways[0]=0;
        ways[1]=0;
        for(int i=2;i<=cost.size();i++){
            ways[i] = min(ways[i-2]+cost[i-2],ways[i-1]+cost[i-1]);
        }
        return ways[cost.size()];
    }
};
