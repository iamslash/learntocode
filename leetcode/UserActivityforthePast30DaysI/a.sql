-- 269ms 81.83%
SELECT 
  activity_date AS day,
  COUNT(DISTINCT(user_id)) AS active_users
FROM
  Activity
GROUP BY
  activity_date
HAVING
  activity_date <= '2019-07-27' AND 
  activity_date > '2019-06-27'
  
