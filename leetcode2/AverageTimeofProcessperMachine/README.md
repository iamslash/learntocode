# Problem

[Average Time of Process per Machine](https://leetcode.com/problems/average-time-of-process-per-machine/)

# Implementation

```sql
-- 339ms 100.00% 0B 100.00%
SELECT 
  s.machine_id, 
  ROUND(AVG(e.timestamp-s.timestamp),3) AS processing_time
FROM Activity s 
JOIN Activity e 
  ON s.machine_id = e.machine_id AND
     s.process_id = e.process_id AND
     s.activity_type = 'start' AND e.activity_type = 'end'
GROUP BY s.machine_id     
```
