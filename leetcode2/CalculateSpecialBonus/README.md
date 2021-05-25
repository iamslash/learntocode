# Problem

[Calculate Special Bonus](https://leetcode.com/problems/calculate-special-bonus/)

# Implementation

```sql
-- 636ms 100.00% 0B 100.00%
SELECT employee_id,
       CASE 
         WHEN MOD(employee_id, 2) = 1 AND LEFT(name, 1) <> 'M'
           THEN salary
         ELSE
           0
       END AS bonus
  FROM Employees;
```
