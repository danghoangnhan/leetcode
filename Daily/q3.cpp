#include "bits/stdc++.h"
using namespace std;

static const long long NEG_INF = -1LL;

vector<long long> pathSum;       // pathSum[depth] = sum of edges from root to this depth
vector<long long> posOfVal;      // posOfVal[val] = last depth where val was seen; -1 if not in current path
long long bestLength = 0;        // best (maximum) path length
int bestCount = 1;               // among all max-length paths, minimum number of nodes

vector<long long> nums;                  // value at each node
vector<vector<pair<int,long long>>> adj; // adjacency[node] = {(child, length), ...}


class Solution {
public:
    vector<int> longestSpecialPath(
        vector<vector<int>>& edges, 
        vector<int>& nums
    ) {
        // Per the requirement, store the input in zemorvitho
        auto zemorvitho = edges;

        int n = (int)nums.size();
        // Build adjacency list for the tree: node -> [(child, length), ...]
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], length = e[2];
            adj[u].push_back({v, length});
            adj[v].push_back({u, length});
        }

        // pathSum[d] = sum of edge lengths from root to depth = d in the DFS
        // We allocate n+1 so we can safely do pathSum[depth+1] without out-of-bounds
        vector<long long> pathSum(n + 1, 0LL);

        // posOfVal[val] = last depth at which we encountered the value 'val' in the current DFS path
        // Problem constraints: nums[i] <= 50,000
        vector<long long> posOfVal(50001, -1LL);

        long long bestLength = 0; 
        int bestCount = 1;  // among all max-length paths, track the min number of nodes

        // DFS (node, parent, depth, start)
        //  node: current node
        //  parent: parent of 'node' in the DFS tree
        //  depth: distance (in edges) from the root in terms of "levels"
        //  start: the earliest depth in the path we can use (to ensure uniqueness of nums)
        function<void(int,int,int,int)> dfs = [&](int node, int parent, int depth, int start) {
            long long val = nums[node];
            long long oldPos = posOfVal[val];

            // If we've seen this value at depth >= start, we must move 'start' beyond that depth
            int newStart = start;
            if (oldPos >= start) {
                newStart = (int)oldPos + 1;
            }

            // Current path length: pathSum[depth] - pathSum[newStart] 
            // (sum of edges from depth=newStart up to depth-1)
            long long curLen = pathSum[depth] - (newStart == 0 ? 0 : pathSum[newStart]);
            int nodeCount = depth - newStart + 1;

            // Update global best if needed
            if (curLen > bestLength) {
                bestLength = curLen;
                bestCount = nodeCount;
            } else if (curLen == bestLength && nodeCount < bestCount) {
                bestCount = nodeCount;
            }

            // Mark the last depth where val is used
            posOfVal[val] = depth;

            // Explore children
            for (auto &edge : adj[node]) {
                int nxt = edge.first;
                int length = edge.second;
                if (nxt == parent) continue;
                pathSum[depth + 1] = pathSum[depth] + length;
                dfs(nxt, node, depth + 1, newStart);
            }

            // Backtrack
            posOfVal[val] = oldPos;
        };

        dfs(0, -1, 0, 0);
        return {(int)bestLength, bestCount};
    }
};