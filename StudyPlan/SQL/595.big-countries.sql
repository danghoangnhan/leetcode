--
-- @lc app=leetcode id=595 lang=mysql
--
-- [595] Big Countries
--

-- @lc code=start
# Write your MySQL query statement below
select name,population,area from World where World.area >=3000000 or World.population >= 25000000 
-- @lc code=end

