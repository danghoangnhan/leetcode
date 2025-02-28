#include <vector>
#include <queue>
#include<bitset>

using namespace std;
using PII = pair<int, int>;

/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start

const int MXN = 200;
const int MXV = 200;
const int INF = 1000000000;
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
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> states;
        vis.reset();
        states.push(make_pair(d[s], s));
        while (!states.empty())
        {
            pair<int,int> state = states.top();
            states.pop();
            if (vis[state.second])
            {
                continue;
            }
            vis[state.second] = true;
            for (int u : v[state.second])
            {
                Edge e = E[u];
                if (d[e.to] > d[e.from] + e.w)
                {
                    d[e.to] = d[e.from] + e.w;
                    p[e.to] = e.from;
                    states.push(make_pair(d[e.to], e.to));
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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int result = -1;
        Dijkstra dijkstra; // declare
        dijkstra.init();
        
        
        for (vector<int> element: times)
        {
            dijkstra.addEdge(element[0], element[1], element[2]); // add a directional Edge
        }
        dijkstra.dijkstra(k); // calculation shortest distance from s
        for (int i = 1; i <= n; i++)
        {
            result  = max(result,dijkstra.d[i]);
            if(dijkstra.d[i] == INF)
                return -1;
        }
        return result;
    }
};
// @lc code=end

