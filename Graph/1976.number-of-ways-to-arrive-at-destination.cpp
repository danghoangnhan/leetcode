/*
 * @lc app=leetcode id=1976 lang=cpp
 *
 * [1976] Number of Ways to Arrive at Destination
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            const int MOD = 1e9 + 7;
    
            vector<vector<pair<int, int>>> adj(n);
            for(auto &road : roads){
                int u = road[0], v = road[1], time = road[2];
                adj[u].push_back({v, time});
                adj[v].push_back({u, time});
            }
            
            vector<long long> dist(n, LLONG_MAX);
            vector<long long> ways(n, 0);
            dist[0] = 0;
            ways[0] = 1;
            
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            pq.push({0, 0});
            
            while(!pq.empty()){
                auto [time, node] = pq.top();
                pq.pop();
                
                if(time > dist[node])
                    continue;
                
                for(auto &[next, t] : adj[node]){
                    if(dist[next] > time + t){
                        dist[next] = time + t;
                        ways[next] = ways[node];
                        pq.push({dist[next], next});
                    }
                    else if(dist[next] == time + t){
                        ways[next] = (ways[next] + ways[node]) % MOD;
                    }
                }
            }
            
            return ways[n - 1];
        }
    };    
// @lc code=end

