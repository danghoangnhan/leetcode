--
-- @lc app=leetcode id=1068 lang=mysql
--
-- [1068] Product Sales Analysis I
--

-- @lc code=start
# Write your MySQL query statement below
select  product_name, year, price from Sales  join Product on Sales.product_id = Product.product_id
-- @lc code=end

