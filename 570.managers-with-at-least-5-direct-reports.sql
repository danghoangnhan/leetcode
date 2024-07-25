--
-- @lc app=leetcode id=570 lang=mysql
--
-- [570] Managers with at Least 5 Direct Reports
--

-- @lc code=start
# Write your MySQL query statement below
SELECT er.name 
FROM Employee ee 
JOIN Employee er ON ee.managerId = er.id 
GROUP BY er.id, er.name
HAVING COUNT(ee.id) >= 5;

-- @lc code=end

