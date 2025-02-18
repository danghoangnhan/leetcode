/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;

struct Node{
    int dictionary[26];
    struct Node *nextNode;
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Node head;
        string result;
        for(auto& str:strs){
            Node *current = &head;
            for(auto& element:str){
                current->dictionary[element-'a']++;
                current=current->nextNode;
            }
        }
        Node *current = &head;
        while(current){

        }



    }
};
// @lc code=end

