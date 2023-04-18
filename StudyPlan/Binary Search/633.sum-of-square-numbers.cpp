/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */

// @lc code=start
class Solution {
public:
     bool judgeSquareSum( int c) {
        // https://en.wikipedia.org/wiki/Fermat%27s_theorem_on_sums_of_two_squares#Related_results
         for ( int i = 2 ; i * i <= c; ++ i) {
             if (c % i != 0 ) continue ;
             int cnt = 0 ;
             while (c % i == 0 ) {
                 ++ cnt;
                c /= i;
            }
            if (i % 4 == 3 && cnt % 2 != 0 ) return  false ;
        }
        return c % 4 != 3 ;
    }
};
// @lc code=end

