#include <vector>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution {
public:
    int convert(char target){
        return int(target - 'a');
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0, hi = letters.size() - 1;
        int mid;
        while (hi >lo) {
            int mid = (hi + lo) / 2;
            if (convert(letters[mid]) < convert(target)) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        for (int i = lo; i < letters.size(); i++){
            if(letters[i]>target)
                return letters[i];
        }
        return letters[0];
        
        }
};
// @lc code=end

