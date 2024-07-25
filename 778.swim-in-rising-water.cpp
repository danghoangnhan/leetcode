/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
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
const int MXV = 2600;
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

struct Dijkstra
{
    const int INF = 1000000000;
    int d[MXV], p[MXV];
    vector<Edge> E;
    vector<int> v[MXV];
    bitset<MXV> vis;

    void init()
    {
        fill(d, d + MXV, INF);
        memset(p, 0, sizeof(p));
        E.clear();
        for (int i = 0; i < MXV; i++)
        {
            v[i].clear();
        }
        vis.reset();
    }

    void addEdge(int from, int to, int w)
    {
        v[from].push_back(E.size());
        E.push_back(Edge{from, to, w});
    }

    void dijkstra(int s)
    {
        d[s] = 0;
        priority_queue<PII, vector<PII>, greater<PII>> states;
        vis.reset();
        states.push(MP(d[s], s));
        while (!states.empty())
        {
            PII state = states.top();
            states.pop();
            if (vis[state.second])
            {
                continue;
            }
            vis[state.second] = true;
            for (int u : v[state.second])
            {
                Edge e = E[u];
                if (d[e.to] > max(d[e.from] , e.w))
                {
                    d[e.to] = max(d[e.from] , e.w);
                    p[e.to] = e.from;
                    states.push(MP(d[e.to], e.to));
                }
            }
        }
    }
};

/*
Usage
Dijkstra dijkstra; // declare
dijkstra.init();
dijsktra.addEdge(int from, int to, int w); // add a directional Edge
dijkstra.dijkstra(int s) // calculation shortest distance from s
*/
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        Dijkstra dijkstra; // declare
        dijkstra.init();
        
        int m = grid.size();
        int n = grid[0].size();
        int source = 0;
        int target = (m - 1) * n + (n - 1);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int current = i * n + j;
                if (i > 0) {
                    int up = (i - 1) * n + j;
                    dijkstra.addEdge(current, up, max(grid[i][j] , grid[i - 1][j]));
                }
                if (j > 0) {
                    int left = i * n + (j - 1);
                    dijkstra.addEdge(current, left, max(grid[i][j] , grid[i][j - 1]));
                }
                if (i < m - 1) {
                    int down = (i + 1) * n + j;
                    dijkstra.addEdge(current, down, max(grid[i][j] , grid[i + 1][j]));
                }
                if (j < n - 1) {
                    int right = i * n + (j + 1);
                    dijkstra.addEdge(current, right, max(grid[i][j] , grid[i][j + 1]));
                }
            }
        }
        dijkstra.dijkstra(source);
        return dijkstra.d[target];
    }
};
// @lc code=end

