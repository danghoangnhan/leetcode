#include <vector> 
#include <map>
using namespace std;
/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int helper(int row,int column,bool matrixIndex){
        if (row>=this->rows ||column>=this->cols){return 0;}
        pair<int,int> currentIndex = make_pair(row,column);
                if (this->cache.count(currentIndex)){
                    int down = helper(row+1,column);
                    int right = helper(row,column+1);
                    int diag = helper(row+1,column+1);
                    this->cache.emplace(currentIndex,(matrixIndex)? 1 + min(down,min(right,diag)):0);
                }
        return cache[currentIndex];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        this->cols = matrix[0].size();
        this->rows = matrix.size();
        helper(0,0);   
        return max(cache.values())**2;
    }
    private:
        int cols,rows;
        map<pair<int,int>,int> cache;
};
// @lc code=end

