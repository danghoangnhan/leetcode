#include <set>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> visited;
        for(int element:nums){
            if(visited.count(element)){
                return true;
            }
            visited.insert(element);
        }
        return false;
    }
};
