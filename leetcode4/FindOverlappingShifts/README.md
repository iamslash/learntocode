# Problem

[Find Overlapping Shifts](https://leetcode.com/problems/find-overlapping-shifts/description/)

# Implementation

```sql
-- 725ms 5.36%
SELECT e1.employee_id,
       COUNT(*) AS overlapping_shifts
  FROM EmployeeShifts e1 
  JOIN EmployeeShifts e2
    ON e1.employee_id = e2.employee_id
 WHERE e1.start_time < e2.start_time AND
       e1.end_time > e2.start_time
 GROUP BY e1.employee_id
 ORDER BY employee_id
```
