#include <vector>
#include <set>
using namespace std;
/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 */

// @lc code=start
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> visited;
        for (int i = 0; i < arr.size(); i++){
            if (visited.count(arr[i]*2)||( arr[i]%2==0 && visited.count(arr[i]/2))){
                return true;
            }
            visited.emplace(arr[i]);
        }
        return false;
    }
};
// @lc code=end

