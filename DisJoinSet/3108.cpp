#include "bits/stdc++.h"
using namespace std;

class DSU {
    public:
        vector<int> parent, rank;
        
        DSU(int n) : parent(n), rank(n, 0) {
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        
        int find(int a) {
            if (parent[a] != a)
                parent[a] = find(parent[a]);
            return parent[a];
        }
        
        bool unionn(int a, int b) {
            int pa = find(a), pb = find(b);
            if (pa == pb) return false;
            if (rank[pa] < rank[pb])
                swap(pa, pb);
            parent[pb] = pa;
            if (rank[pa] == rank[pb])
                rank[pa]++;
            return true;
        }
    };
    
class Solution {
    public:
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
            DSU dsu(n);

            for (auto &e : edges) {
                dsu.unionn(e[0], e[1]);
            }
            
            int init_val = (1 << 17) - 1;  // 131071
            vector<int> compAnd(n, init_val);
            
            for (auto &e : edges) {
                int u = e[0], w = e[2];
                int root = dsu.find(u);
                compAnd[root] &= w;
            }
            
            vector<int> ans;
            ans.reserve(query.size());
            for (auto &q : query) {
                int s = q[0], t = q[1];
                if (dsu.find(s) != dsu.find(t))
                    ans.push_back(-1);
                else {
                    int root = dsu.find(s);
                    ans.push_back(compAnd[root]);
                }
            }
            return ans;
        }
    };
    