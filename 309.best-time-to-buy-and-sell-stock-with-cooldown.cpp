#include <map>
#include <vector>
#include<pair>
using namespace std;

/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
struct stage{
    int i;
    bool buying;
}
class Solution {
public:
    vector<int>& prices;
    map<pair<int,bool>,int>caching;

    int dfs(pair<int,bool> currentStage){
        if (i >= this->prices.size()){
            return 0;
        }
        if (this->caching.count(i,buying)){
            return this->caching(i,buying);
        }
        stage cooldown = dfs(currentStage.i+1,currentStage.buying);
        if (currentStage.buying){
            int buy = dfs()
        }else{

        }
        
    };
    int maxProfit(vector<int>& prices) {
        this->prices = prices;
    }
};
// @lc code=end

