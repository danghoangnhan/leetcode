--
-- @lc app=leetcode id=197 lang=mysql
--
-- [197] Rising Temperature
--

-- @lc code=start
# Write your MySQL query statement below
SELECT table_1.id AS Id
FROM Weather AS table_1
JOIN Weather AS table_2 
ON table_1.recordDate = DATE_ADD(table_2.recordDate, INTERVAL 1 DAY)
WHERE table_1.temperature > table_2.temperature;
-- @lc code=end

