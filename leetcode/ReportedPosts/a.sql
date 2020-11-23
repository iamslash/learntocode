

-- 423ms 69.36%
SELECT 
  extra AS report_reason, 
  COUNT(DISTINCT(post_id)) AS report_count
FROM
  Actions
WHERE 
  action = 'report' AND
  action_date = DATE('2019-07-05') - 1
GROUP BY
  extra
;  
  
