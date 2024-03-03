# Problem

[Snaps Analysis](https://leetcode.com/problems/snaps-analysis/)

# Implementation

```sql
-- 1352ms 18.69% 0B 100.00%
   SELECT b.age_bucket,
          ROUND(SUM(IF(a.activity_type = 'send', a.time_spent, 0)) * 100 / SUM(a.time_spent), 2) AS send_perc,
          ROUND(SUM(IF(a.activity_type = 'open', a.time_spent, 0)) * 100 / SUM(a.time_spent), 2) AS open_perc
     FROM Activities a
LEFT JOIN Age b
       ON a.user_id = b.user_id
 GROUP BY b.age_bucket      
```
