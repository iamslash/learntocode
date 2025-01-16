# Problem

[Server Utilization Time](https://leetcode.com/problems/server-utilization-time/description/)

# Implementation

```sql
-- 715ms 36.99%
SELECT FLOOR(SUM(CASE 
                   WHEN session_status = 'start' 
                     THEN -unix_timestamp(status_time) 
                     ELSE unix_timestamp(status_time) 
                   END) / (60*60*24)) AS total_uptime_days
  FROM servers
```
