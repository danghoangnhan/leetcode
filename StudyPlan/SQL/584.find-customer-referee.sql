--
-- @lc app=leetcode id=584 lang=mysql
--
-- [584] Find Customer Referee
--

-- @lc code=start
# Write your MySQL query statement below
SELECT  Customer.name
FROM Customer
WHERE (Customer.referee_id IS NULL OR  Customer.referee_id != 2)
-- @lc code=end

