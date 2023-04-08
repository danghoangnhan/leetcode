/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long int  lo = 1, hi = n;
        long long int mid;
        while (hi - lo > 1) {
            long long int mid = (hi + lo) / 2;
            if (guess(mid) ==1) {
                lo = mid + 1;
            }
            if (guess(mid) ==-1) {
                hi = mid;
            }
            if (guess(mid) ==0){
                return mid;
            }
        }
        return (guess(lo)==0)?lo:hi;
    }
    int guest(int num){
        if (num>pick){
            return -1;
        }
        if (num<pick){
            return 1;
        }
        return 0;
    }
private:
    int pick;
};
// @lc code=end

