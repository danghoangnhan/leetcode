--
-- @lc app=leetcode id=620 lang=mysql
--
-- [620] Not Boring Movies
--

-- @lc code=start
# Write your MySQL query statement below
SELECT id, movie, description, rating
FROM Cinema
WHERE description != 'boring' and id %2 !=0
ORDER BY rating DESC;
-- @lc code=end

