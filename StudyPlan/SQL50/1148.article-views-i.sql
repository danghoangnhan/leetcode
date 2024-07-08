--
-- @lc app=leetcode id=1148 lang=mysql
--
-- [1148] Article Views I
--

-- @lc code=start
# Write your MySQL query statement below
select distinct viewer_id as id from Views where author_id = viewer_id order by viewer_id; 
-- @lc code=end

