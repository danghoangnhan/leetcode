#include <vector>
#include <queue>
#include<bitset>
#include<math.h>

using namespace std;
using PII = pair<int, int>;
/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */

// @lc code=start
const int MXN = 10000;
const int MXV = 10000;
const int INF = 1000000000;
struct Edge
{
    int from, to, w;
    bool operator<(const Edge& rhs){
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
                int currentEffort = max(d[e.from] , e.w);
                if (d[e.to] > currentEffort)
                {
                    d[e.to] = currentEffort;
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
private:
    vector<vector<int>> dirs =  { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        Dijkstra dijkstra; // declare
        dijkstra.init();
        int m = heights.size();
        int n = heights[0].size();
        int destination=m*(m-1)+(n-1);
        
        if (m==1 && n ==1)return 0;
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                for (vector<int> dir : dirs) {
                    int newRow = i + dir[0];
                    int newCol = j + dir[1];
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n)
                        dijkstra.addEdge(m*i+j,m*newRow+newCol,abs(heights[newRow][newCol] - heights[i][j]));
                }
            }
        }
        dijkstra.dijkstra(0);
        return dijkstra.d[destination];
    }
};
// @lc code=end

