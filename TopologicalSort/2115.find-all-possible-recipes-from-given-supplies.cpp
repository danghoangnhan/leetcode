/*
 * @lc app=leetcode id=2115 lang=cpp
 *
 * [2115] Find All Possible Recipes from Given Supplies
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_set<string> available(supplies.begin(), supplies.end());
        unordered_map<string, vector<int>> dependents;
        vector<int> missingCount(recipes.size(), 0);

        for (int i = 0; i < recipes.size(); i++) {
            for (const auto& ing : ingredients[i]) {
                if (available.find(ing) == available.end()) {
                    missingCount[i]++;
                    dependents[ing].push_back(i);
                }
            }
        }

        queue<int> q;
        vector<string> result;
        for (int i = 0; i < recipes.size(); i++) {
            if (missingCount[i] == 0) {
                q.push(i);
                result.push_back(recipes[i]);
                available.insert(recipes[i]);
            }
        }
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            string currRecipe = recipes[curr];

            if (dependents.count(currRecipe)) {
                for (int recId : dependents[currRecipe]) {
                    missingCount[recId]--;

                    if (missingCount[recId] == 0) {
                        q.push(recId);
                        result.push_back(recipes[recId]);
                        available.insert(recipes[recId]);
                    }
                }
            }
        }
        return result;
    }
};

// @lc code=end

