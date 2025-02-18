--
-- @lc app=leetcode id=1731 lang=mysql
--
-- [1731] The Number of Employees Which Report to Each Employee
--

-- @lc code=start
# Write your MySQL query statement below
select e1.employee_id, e1.name, count(e2.reports_to) as reports_count, round(avg(e2.age)) as average_age 
from Employees as e1 join Employees as e2
on e1.employee_id = e2.reports_to
group by e2.reports_to
order by employee_id asc;


-- @lc code=end

