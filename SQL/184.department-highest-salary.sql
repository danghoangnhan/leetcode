--
-- @lc app=leetcode id=184 lang=mysql
--
-- [184] Department Highest Salary
--

-- @lc code=start
# Write your MySQL query statement below
SELECT
  d.name       AS Department,
  e.name       AS Employee,
  e.salary     AS Salary
FROM
  Employee e
  JOIN Department d
    ON e.departmentId = d.id
WHERE
  e.salary = (
    SELECT MAX(salary)
    FROM Employee
    WHERE departmentId = e.departmentId
  )
ORDER BY
  d.name,
  e.name;
-- @lc code=end

