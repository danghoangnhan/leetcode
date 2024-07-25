--
-- @lc app=leetcode id=1729 lang=mysql
--
-- [1729] Find Followers Count
--

-- @lc code=start
# Write your MySQL query statement below
select user_id , count(follower_id) as followers_count 
from Followers 
group by user_id 
order by user_id
-- @lc code=end

