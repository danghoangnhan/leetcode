/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

struct Node {
    int v;
    Node* next[26];
    Node() {
        v = 0;
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

class WordDictionary {
public:
    WordDictionary() {
        this->rootNode = new Node();
    }
    
    void addWord(string word) {
        Node* currentNode = this->rootNode;
        for (int i = 0; i < word.size(); i++) {
            int v = word[i] - 'a';
            if (currentNode->next[v] == NULL) {
                currentNode->next[v] = new Node();
            }
            currentNode = currentNode->next[v];
            ++currentNode->v;
        }
    }
    
    bool search(string word) {
        Node* currentNode = this->rootNode;
        for (int i = 0; i < word.size(); i++) {
            int v = word[i] - 'a';
            if (currentNode->next[v] == NULL) {
                return false;
            }
            if (currentNode->v == 0) {
                return false;
            }
            currentNode = currentNode->next[v];
        }
        return true;
    }

private:
    Node* rootNode;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

