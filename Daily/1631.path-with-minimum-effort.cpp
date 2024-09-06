/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */

// @lc code=start
#include <bits/stdc++.h>
#define MXV 1000000
using PII = pair<int,int>;
#define MP make_pair
using namespace std;

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
                int newEffort = max(d[e.from] , e.w);
                if (d[e.to] > newEffort)
                {
                    d[e.to] =newEffort;
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
    int minimumEffortPath(vector<vector<int>>& heights) {
        Dijkstra dijkstra;
        dijkstra.init();
        
        int m = heights.size();
        int n = heights[0].size();
        int source = 0; // Top-left corner
        int target = (m - 1) * n + (n - 1); // Bottom-right corner

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int current = i * n + j;
                if (i > 0) {
                    int up = (i - 1) * n + j;
                    dijkstra.addEdge(current, up, abs(heights[i][j] - heights[i - 1][j]));
                }
                if (j > 0) {
                    int left = i * n + (j - 1);
                    dijkstra.addEdge(current, left, abs(heights[i][j] - heights[i][j - 1]));
                }
                if (i < m - 1) {
                    int down = (i + 1) * n + j;
                    dijkstra.addEdge(current, down, abs(heights[i][j] - heights[i + 1][j]));
                }
                if (j < n - 1) {
                    int right = i * n + (j + 1);
                    dijkstra.addEdge(current, right, abs(heights[i][j] - heights[i][j + 1]));
                }
            }
        }

        dijkstra.dijkstra(source);
        return dijkstra.d[target];
    }
};

// @lc code=end

