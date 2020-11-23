-- 399ms 62.43%
SELECT
  player_id,
  MIN(event_date) AS first_login
FROM 
  Activity
GROUP BY player_id
;
