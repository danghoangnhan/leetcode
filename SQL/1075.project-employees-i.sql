--
-- @lc app=leetcode id=1075 lang=mysql
--
-- [1075] Project Employees I
--

-- @lc code=start
# Write your MySQL query statement below
select project_id , ROUND(AVG(Employee.experience_years),2) as average_years 
from Project join Employee 
on Project.employee_id = Employee.employee_id
group by Project.project_id
-- @lc code=end

