--
-- @lc app=leetcode id=1934 lang=mysql
--
-- [1934] Confirmation Rate
--

-- @lc code=start
# Write your MySQL query statement below
SELECT 
    Signups.user_id, 
    ROUND(
        COALESCE(SUM(CASE WHEN Confirmations.action = 'confirmed' THEN 1 ELSE 0 END) / 
        NULLIF(COUNT(Confirmations.action), 0), 0)
    , 2) AS confirmation_rate
FROM 
    Signups
LEFT JOIN 
    Confirmations 
ON 
    Signups.user_id = Confirmations.user_id
GROUP BY 
    Signups.user_id;

-- @lc code=end

