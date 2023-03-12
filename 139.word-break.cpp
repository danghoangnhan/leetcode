#include<string>
#include<vector>
#include<set>
#define FOR(i, L, R) for(int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i > (int)R; --i)
using namespace std;
/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */
class Node{
public:
    bool isWord;
    Node *next[26];
    Node(){
        for (auto &a : next) a = nullptr;
        isWord = false;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* current = this->root;
        for(char x:word){
            int v = x - 'a';
            if (!current->next[v])current->next[v] = new Node();
            current = current->next[v];
        }
        current->isWord = true;
    }
    
    bool search(string word) {
        Node* current = this->root;
        for (auto &a : word) {
            int v = tolower(a) - 'a';
            if (!current->next[v])return false;
            current = current->next[v];
        }
        return current->isWord;
    }
    
    bool startsWith(string prefix) {
        Node* current = this->root;
        for (auto &a : prefix) {
            int v = a - 'a';
            if (!current->next[v])return false;
                current = current->next[v];
        }
        return true;
    }
};


// @lc code=start
class Solution {
private:
    bool visited[300] = {};
    string s;
    Trie* trie;
    set<string> dict;
    bool dfs(int i) {
            if (i == size(s))return true;
            if (!visited[i]) {
                visited[i] = true;
                for (int j = i; j < size(s); j++) {
                    if (this->trie->search(s.substr(i,j+1)) && dfs(j+1))
                        return true;
                }
            }
            return false;
        };
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* obj = new Trie();
        this->s = s;
        for (auto word:wordDict){obj->insert(word);}
        dfs(0);        
    }
};
// @lc code=end

