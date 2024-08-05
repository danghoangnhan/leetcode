--
-- @lc app=leetcode id=1070 lang=mysql
--
-- [1070] Product Sales Analysis III
--

-- @lc code=start
# Write your MySQL query statement below
select product_id, year as first_year, quantity, price
from Sales
where (product_id, year) in (select product_id, min(year) as year from Sales
group by product_id);year) in (select product_id, min(year) as year from Sales
group by product_id);select product_id, year as first_year, quantity, price
from Sales
where (product_id, year) in (select product_id, min(year) as year from Sales
group by product_id);
-- @lc code=end

