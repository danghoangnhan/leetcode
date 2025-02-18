--
-- @lc app=leetcode id=1978 lang=mysql
--
-- [1978] Employees Whose Manager Left the Company
--

-- @lc code=start
# Write your MySQL query statement below
SELECT ee.employee_id 
FROM Employees AS ee 
LEFT JOIN Employees AS er 
ON ee.manager_id = er.employee_id
WHERE 
        ee.salary < 30000 
    AND er.employee_id IS NULL 
    AND ee.manager_id IS NOT NULL 
ORDER BY ee.employee_id;
-- @lc code=end

