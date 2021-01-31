# Problem

[Find Total Time Spent by Each Employee](https://leetcode.com/problems/find-total-time-spent-by-each-employee/)

# Implementation

```sql
-- 484ms 100.00% 0B 100.00%
  SELECT event_day AS day,
         emp_id,
         SUM(out_time - in_time) AS total_time
    FROM Employees
GROUP BY event_day, emp_id
ORDER BY event_day, emp_id
```
