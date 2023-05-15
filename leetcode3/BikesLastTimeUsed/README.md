# Problem

[Bikes Last Time Used](https://leetcode.com/problems/bikes-last-time-used/)

# Implementation

```sql
-- 625ms 100.00% 0B 100.00%
  SELECT bike_number,
         MAX(end_time) AS end_time
    FROM Bikes
GROUP BY bike_number;
```
