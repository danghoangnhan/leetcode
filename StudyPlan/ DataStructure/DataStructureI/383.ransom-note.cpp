#include <vector>
using namespace;
/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>magazine_count(26,0);
        for (auto word:magazine){
            magazine_count[word-'a']++;
        }
        for (auto word:ransomNote){
            int index = word-'a';
            if (magazine_count[index]==0)
            {
                return false;
            }
            
            magazine_count[index]--;
        }
    return true;  
    }
};
// @lc code=end

