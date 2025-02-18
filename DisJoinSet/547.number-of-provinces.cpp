/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int,int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using dvt = double;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 302;
const double EPS = 1e-9;
const int MOD = 1e9+7;
#define MP make_pair
#define PB push_back
#define Fi first
#define Se second
#define FOR(i, L, R) for(int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i > (int)R; --i)
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);


struct DisjointSet
{
    int p[MXV], sz[MXV];
    void init(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            p[i] = i;
            sz[i] = 1;
        }
    }
    int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
    void Union(int u, int v)
    {
        u = find(u);
        v = find(v);
        if(u == v)
        {
            return;
        }
        if(sz[u] < sz[v])
        {
            swap(u, v);
        }
        sz[u] += sz[v];
        p[v] = u;
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        DisjointSet djs;
        djs.init(isConnected.size());

        for (int i = 0; i < isConnected.size(); ++i) {
            for (int j = i + 1; j < isConnected.size(); ++j) {
                if (i!=j && isConnected[i][j]) {
                    djs.Union(i, j);
                }
            }
        }
        unordered_set<int> province;
        for (int i = 0; i < isConnected.size(); ++i) {
            province.insert(djs.find(i));
        }

    return province.size();
    }
};
// @lc code=end

