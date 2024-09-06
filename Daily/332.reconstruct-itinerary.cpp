/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:    
    void dfs(
        string from,
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph,
        list<string>& itinerary) {
        
        while (!graph[from].empty()) {
            string next = graph[from].top();
            graph[from].pop();
            dfs(next, graph, itinerary);
        }
        itinerary.push_front(from);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        
        for (auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        list<string> itinerary;
        dfs("JFK", graph, itinerary);
        return vector<string>(itinerary.begin(), itinerary.end());
    }
};
// @lc code=end

