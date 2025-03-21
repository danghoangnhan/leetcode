#include <vector>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        stack<pair<int,int>>flood;
        vector<pair<int,int>>location = {make_pair(0,1),make_pair(0,-1),
                                        make_pair(1,0),make_pair(-1,0)};
        flood.emplace(make_pair(sr,sc));
        while (!flood.empty()){
            pair<int,int> currentPoint = flood.top();
            flood.pop();
            for (auto element:location){
                pair<int,int> newPoint = make_pair(currentPoint.first + element.first
                                                    ,currentPoint.second + element.second);
                if (newPoint.first>=0
                    &&newPoint.first<image.size()
                    &&newPoint.second>=0
                    &&newPoint.second<image[0].size()){
                        if (    image[currentPoint.first][currentPoint.second]==image[newPoint.first][newPoint.second]
                            &&  image[newPoint.first][newPoint.second]!=color){
                            flood.emplace(newPoint);
                        }
                    }
                }
                image[currentPoint.first][currentPoint.second]=color;
        }
        return image;
    }
};
// @lc code=end

