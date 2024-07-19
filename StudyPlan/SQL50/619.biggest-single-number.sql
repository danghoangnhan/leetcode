--
-- @lc app=leetcode id=619 lang=mysql
--
-- [619] Biggest Single Number
--

-- @lc code=start
# Write your MySQL query statement below
SELECT MAX(num_agg) AS num
FROM (
    SELECT num AS num_agg
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(*) = 1
) AS singles;
-- @lc code=end

