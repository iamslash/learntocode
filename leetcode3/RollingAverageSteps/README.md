# Problem

[Rolling Average Steps](https://leetcode.com/problems/rolling-average-steps/)

# Implementation

```sql
SELECT user_id,
       steps_date,
       ROUND(rolling_avg, 2) AS rolling_average
  FROM (SELECT user_id,
               steps_date,
               AVG(steps_count) OVER () AS rolling_avg,
               COUNT(steps_date) OVER () AS rolling_cnt
          FROM Steps
      ORDER BY user_id ASC,
               steps_date ASC) t
 WHERE t.rolling_cnt = 3;

-- 437ms 100.00% 0B 100.00%
SELECT user_id,
       steps_date,
       ROUND(rolling_avg, 2) AS rolling_average
  FROM (SELECT user_id,
               steps_date,
               AVG(steps_count) OVER (PARTITION BY user_id
                                          ORDER BY steps_date
                                     RANGE BETWEEN INTERVAL '2' DAY PRECEDING AND
                                                    CURRENT ROW) AS rolling_avg,
               COUNT(steps_date) OVER (PARTITION BY user_id
                                          ORDER BY steps_date
                                     RANGE BETWEEN INTERVAL '2' DAY PRECEDING AND
                                                    CURRENT ROW) AS rolling_cnt               
          FROM Steps
      ORDER BY user_id ASC,
               steps_date ASC) t
 WHERE t.rolling_cnt = 3;
```
