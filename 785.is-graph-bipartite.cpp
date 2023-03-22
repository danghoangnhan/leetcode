#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Bipartite{

public:
    vector<int> map[50050];
    int visit[50050];
    bool valid;

    void check(int start){

        stack<int> st;
        st.push(start);
        visit[start] = 1;

        while (valid && !st.empty())
        {
            int cur = st.top();
            st.pop();

            for (int i = 0; i < this->map[cur].size(); i++)
            {
                int next = this->map[cur][i];

                if (this->visit[next] == -1)
                {
                    st.push(next);
                    if (this->visit[cur] == 1)
                        this->visit[next] = 2;
                    else
                        this->visit[next] = 1;
                }
                else if (this->visit[cur] == this->visit[next])
                    this->valid = false;
            }
        }
    }
};


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        Bipartite bipartite;
        for (int i = 0; i < graph.size(); i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                bipartite.map[i].push_back(graph[i][j]);
            }
        }
        // -1 : not visit, 1 : tsudere, 2 : proud
        memset(bipartite.visit, -1, sizeof(bipartite.visit));
        bipartite.valid = true;

        for (int i = 1; i <= graph.size(); i++)
        {
            if (bipartite.valid && bipartite.visit[i] == -1)
            {
                bipartite.check(i);
            }
        }
        return bipartite.valid;
    }
};
// @lc code=end