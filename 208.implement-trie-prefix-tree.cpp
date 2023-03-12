#include<string>
#include<vector>
#define FOR(i, L, R) for(int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i > (int)R; --i)
using namespace std;
/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */
#include<string>
#include<vector>
#define FOR(i, L, R) for(int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i > (int)R; --i)
using namespace std;
/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
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
// @lc code=start
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

