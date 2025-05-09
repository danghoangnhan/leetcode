--
-- @lc app=leetcode id=181 lang=mysql
--
-- [181] Employees Earning More Than Their Managers
--

-- @lc code=start
# Write your MySQL query statement below

SELECT 
  e.name AS Employee
FROM 
  Employee e
WHERE 
  e.managerId IS NOT NULL
  AND e.salary > (
    SELECT m.salary
    FROM Employee m
    WHERE m.id = e.managerId
  );
-- @lc code=end

