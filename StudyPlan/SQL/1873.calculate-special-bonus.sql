--
-- @lc app=leetcode id=1873 lang=mysql
--
-- [1873] Calculate Special Bonus
--

-- @lc code=start
# Write your MySQL query statement below
SELECT employee_id,
       CASE 
           WHEN Employees.employee_id % 2 = 1 AND SUBSTRING(name, 1, 1) != 'M' THEN salary 
           ELSE 0 
       END AS bonus
FROM Employees
ORDER BY employee_id;
-- @lc code=end

