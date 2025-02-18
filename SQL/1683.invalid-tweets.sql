--
-- @lc app=leetcode id=1683 lang=mysql
--
-- [1683] Invalid Tweets
--

-- @lc code=start
# Write your MySQL query statement below
select tweet_id from Tweets where  LENGTH(content) > 15; 
-- @lc code=end

