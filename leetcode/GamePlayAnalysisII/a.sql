
-- 405ms 63.50%
SELECT
  player_id, 
  device_id
FROM
  Activity
WHERE
  (player_id, event_date) IN
  (
    SELECT 
      player_id, 
      MIN(event_date)
    FROM 
      Activity
    GROUP BY
      player_id
  )
;  
  
