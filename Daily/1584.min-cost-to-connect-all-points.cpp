/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
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
const int MXV = 1005;
const double EPS = 1e-9;
const int MOD = 1e9+7;
#define MP make_pair
#define PB push_back
#define Fi first
#define Se second
#define FOR(i, L, R) for(int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i > (int)R; --i)
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

struct Edge
{
    int from, to, w;
    bool operator<(const Edge& rhs) // optional
    {
        return w < rhs.w;
    }
};

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
    bool Union(int u, int v)
    {
        u = find(u);
        v = find(v);
        if(u == v)
        {
            return false;
        }
        if(sz[u] < sz[v])
        {
            swap(u, v);
        }
        sz[u] += sz[v];
        p[v] = u;
        return true;
    }
};

/*
Usage
DisjointSet djs; // declare
djs.init(int n); // initialize from vertex 0 to vertex n
djs.find(int u) // find the parent of vertex u
djs.Union(int u, int v) // union vertex u and v
*/

class Solution {
public:

    int MST(vector<Edge>& edges,int n){

        DisjointSet djs;

        int ans = 0;

        sort(edges.begin(), edges.end());
        djs.init(n);

        for (auto edge : edges){
            if (djs.Union(edge.from, edge.to)){
                ans += edge.w;
            }
        }
    return ans;
}
int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int minCostConnectPoints(vector<vector<int>>& points) {
    vector<Edge> edges;

    for(int i=0;i<points.size();i++){
        for(int j=0;j<points.size();j++){
            if(i!=j){
                int w = manhattanDistance(points[i][0], points[i][1], points[j][0], points[j][1]);
                edges.push_back({i, j, w});
            }
        }
    }
    return MST(edges,points.size());
}
};
// @lc code=end

