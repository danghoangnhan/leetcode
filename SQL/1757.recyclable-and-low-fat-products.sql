--
-- @lc app=leetcode id=1757 lang=mysql
--
-- [1757] Recyclable and Low Fat Products
--

-- @lc code=start
# Write your MySQL query statement below
select product_id from Products where Products.low_fats = 'Y' and Products.recyclable = 'Y'
-- @lc code=end

