--
-- @lc app=leetcode id=185 lang=mysql
--
-- [185] Department Top Three Salaries
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
  (
    SELECT COUNT(DISTINCT salary)
    FROM Employee x
    WHERE
      x.departmentId = e.departmentId
      AND x.salary > e.salary
  ) < 3
ORDER BY
  Department    ASC,
  Salary        DESC;
-- @lc code=end

