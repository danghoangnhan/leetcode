--
-- @lc app=leetcode id=1211 lang=mysql
--
-- [1211] Queries Quality and Percentage
--

-- @lc code=start
# Write your MySQL query statement below
WITH QueryMetrics AS (
    SELECT
        query_name,
        AVG(rating * 1.0 / position) AS quality,
        SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) * 100.0 / COUNT(*) AS poor_query_percentage
    FROM
        Queries
    WHERE
        query_name IS NOT NULL
    GROUP BY
        query_name
)
SELECT
    query_name,
    ROUND(quality, 2) AS quality,
    ROUND(poor_query_percentage, 2) AS poor_query_percentage
FROM
    QueryMetrics;
-- @lc code=end

