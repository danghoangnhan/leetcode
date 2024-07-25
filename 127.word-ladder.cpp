/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
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
const int MXV = 5001;
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
        memset(p, -1, sizeof(p));
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
                if (d[e.to] > d[e.from] + e.w)
                {
                    d[e.to] =  d[e.from] + e.w;
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
int countDifferingCharacters(const std::string& str1, const std::string& str2) {

    int differingCount = 0;

    for (size_t i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i]) {
            differingCount++;
        }
        if(differingCount>1){
            return false;
        }
    }

    return true;
}
int ladderLength(string beginWord, string endWord, vector<string>&  wordList) {
    
    Dijkstra dijkstra;
    dijkstra.init();
    
    int source =  wordList.size();
    int destine = -1;


    for(int i=0;i<wordList.size();i++){
        
        if(countDifferingCharacters(wordList[i],beginWord)){
            dijkstra.addEdge(source,i, 1);
        }
        if(wordList[i]==endWord){
            destine = i;
        }
        for(int j=0;j<wordList.size();j++){
            if(i!=j && countDifferingCharacters(wordList[i],wordList[j])){
                dijkstra.addEdge(i,j, 1);
            }
        }
    }
    if(destine==-1) return 0;
    dijkstra.dijkstra(source);
    return dijkstra.p[destine]==-1?0:dijkstra.d[destine]+1;
}
};
// @lc code=end

