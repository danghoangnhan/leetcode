--
-- @lc app=leetcode id=1661 lang=mysql
--
-- [1661] Average Time of Process per Machine
--

-- @lc code=start
# Write your MySQL query statement below
WITH ProcessTimes AS (
    SELECT
        machine_id,
        AVG(end_time - start_time) AS avg_process_time
    FROM (
        SELECT
            machine_id,
            process_id,
            MAX(CASE WHEN activity_type = 'end' THEN timestamp END) AS end_time,
            MAX(CASE WHEN activity_type = 'start' THEN timestamp END) AS start_time
        FROM
            Activity
        GROUP BY
            machine_id,
            process_id
    ) AS process_intervals
    GROUP BY
        machine_id
)
SELECT
    machine_id,
    ROUND(avg_process_time, 3) AS processing_time
FROM
    ProcessTimes;



-- @lc code=end

