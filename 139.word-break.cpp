#include<string>
#include<vector>
#include<unordered_set>
#include<iostream>

#define FOR(i, L, R) for(int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i > (int)R; --i)
#define MAX 300
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
public:
    vector<bool> dp;
    Solution(){
        for (int i = 0; i <=300; i++){
            dp.push_back(false);
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for(auto word:wordDict){
            trie.insert(word);
        }
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        for(int end=1;end<=s.length();end++){
            for(int start = end-1 ; start>=0;start--){
                string prefix = s.substr(start,end-start);
                if (dict.count(prefix))
                {
                    if(start == 0||dp[start-1] ){
                        this->dp[end-1] = true;
                        cout << start  <<" "<< end <<endl;
                        break;
                    }
                }
            }
        }
        return this->dp[(s.length()-1)];        
    }       
};
int main(){
    Solution solution;
    vector<string> pattern = {"apple","pen"};
    string s = "applepenapple";
    for (int i = 0; i <s.size() ; i++)
    {
        cout<<solution.dp[i];
    }
    cout<<endl;
    cout<< solution.wordBreak(s,pattern) <<endl;
    for (int i = 0; i <s.size() ; i++)
    {
        cout<<solution.dp[i];
    }
    
    return 0;
}
// @lc code=end

