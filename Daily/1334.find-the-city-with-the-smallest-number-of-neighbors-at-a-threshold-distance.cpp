/*
 * @lc app=leetcode id=1334 lang=cpp
 *
 * [1334] Find the City With the Smallest Number of Neighbors at a Threshold Distance
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
const int MXV = 105;
const double EPS = 1e-9;
const int MOD = 1e9+7;
#define MP make_pair
#define PB push_back
#define Fi first
#define Se second
#define FOR(i, L, R) for(int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i > (int)R; --i)
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

template <typename T> struct FloydWarshall
{
    T d[MXV][MXV];
    void init() {
        for (int i = 0; i < MXV; ++i) {
            fill(d[i], d[i] + MXV, INF);
            d[i][i] = 0;
        }         
    }
    void floydWarshall(int n)
    {
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (d[i][k] != INF && d[k][j] != INF) {
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }
        }
    }
};
/*
usage
FloydWarshall<int> floydWarshall; // declare with distace's type
floydWarshall.init(); // initialize
FloydWarshall.floydWarshall(); // calculate all-pair shortest path
*/
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        FloydWarshall<int> floydWarshall;
        floydWarshall.init();
        
        for(const auto& edge : edges) {
            floydWarshall.d[edge[0]][edge[1]] = edge[2];
            floydWarshall.d[edge[1]][edge[0]] = edge[2];
        }
        floydWarshall.floydWarshall(n);

        int minReachable = INF;
        int resultCity = -1;
    
        for (int i = 0; i < n; ++i) {
            int reachableCount = 0;
            for (int j = 0; j < n; ++j) {
                if (floydWarshall.d[i][j] <= distanceThreshold) {
                    ++reachableCount;
                }
            }
            
            if (reachableCount < minReachable) {
                minReachable = reachableCount;
                resultCity = i;
            } else if (reachableCount == minReachable && i > resultCity) {
                resultCity = i;
            }
        }
    return resultCity;
    }
};
// @lc code=end

