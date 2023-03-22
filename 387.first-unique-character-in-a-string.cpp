#include <set>
#include <map>
using namespace std;
/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> visited;
        for (int i = s.size()-1; i>=0; i--){visited[s[i]]++;}
        for (int i = 0; i <s.size(); i++){
            if (visited[s[i]]==1)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

