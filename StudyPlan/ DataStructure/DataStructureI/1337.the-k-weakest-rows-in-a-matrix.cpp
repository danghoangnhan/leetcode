#include <vector>
#include<algorithm>
#include <iostream>

using namespace std;
/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<pair<int,int>>check;
    vector<int>result(min(k,int(mat.size())),0);
    for (int i = 0; i < mat.size(); i++){
        int currentSum=0;
        for (int j = 0; j < mat[i].size(); j++){
            currentSum+=mat[i][j];
        }
        check.push_back(make_pair(i,currentSum));
    }
    sort(check.begin(),check.end(),[](const auto& p1, const auto& p2) {
        if (p1.second<p2.second){return true;}
        if (p1.second>p2.second){return false;}
        return p1.first<p2.first;
    });
    
    for(int i=0;i<result.size();i++){
        result[i]=check[i].first;
    }
    return result;
    }
};
// @lc code=end

