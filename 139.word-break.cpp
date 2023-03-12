#include<string>
#include<vector>
#define FOR(i, L, R) for(int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i > (int)R; --i)
using namespace std;
/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */
struct Node
{
    char ch;
    int v;
    Node *next[26];
    Node()
    {
        v = 0;
        FOR(i, 0, 26) next[i] = NULL;
    }
};
void insert(Node *root, string s)
{
    FOR(i, 0, s.size())
    {
        int v = s[i] - 'a';
        if (root->next[v] == NULL)
        {
            root->next[v] = new Node();
        }
        root = root->next[v];
        ++root->v;
        root->ch = s[i];
    }
    return;
}
void search(Node *root, string s)
{
    FOR(i, 0, s.size())
    {
        int v = s[i] - 'a';
        root = root->next[v];
        if (root->v == 1)
        {
            cout << s << ' ' << s.substr(0, i + 1) << '\n';
            return;
        }
    }
    cout << s << ' ' << s << '\n';
}

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<string> v;
        string s;
        Node *root = new Node();
        insert(root, s);
        FOR(i, 0, v.size()) { search(root, wordDict[i]); }
    }
};
// @lc code=end

