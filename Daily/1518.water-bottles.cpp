/*
 * @lc app=leetcode id=1518 lang=cpp
 *
 * [1518] Water Bottles
 */

// @lc code=start
class Solution {
public:
int numWaterBottles(int numBottles, int numExchange) {
        int result = 0;  // Total number of bottles drunk
        int empty = 0;   // Number of empty bottles

        // Loop as long as we have full bottles to drink
        while (numBottles > 0) {
            result += numBottles;  // Drink all current full bottles
            int newBottles = (numBottles + empty) / numExchange;  // New full bottles from exchange
            empty = (numBottles + empty) % numExchange;  // Remaining empty bottles after exchange
            numBottles = newBottles;  // Update number of full bottles
        }
        return result;
    }
};
// @lc code=end

