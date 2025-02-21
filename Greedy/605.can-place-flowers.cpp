/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int count=0;
        for(int i = 0; i < size && count < n; i++) {
        if (flowerbed[i] == 0) {
            bool leftEmpty  = (i == 0) || (flowerbed[i - 1] == 0);
            bool rightEmpty = (i == size - 1) || (flowerbed[i + 1] == 0);
            
            if (leftEmpty && rightEmpty) {
                flowerbed[i] = 1;   
                count++;           
            }
        }
    }
    return (count >= n);
    }
};
// @lc code=end

