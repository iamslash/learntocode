# Problem

[Highest Salaries Difference](https://leetcode.com/problems/highest-salaries-difference/)

# Implementation

```sql
-- 599ms 100.00% 0B 100.00%
SELECT ABS(MAX(IF(department = 'Engineering',salary,0)) - 
         MAX(IF(department = 'Marketing',salary,0))) AS salary_difference
  FROM Salaries
 WHERE department in ('Engineering', 'Marketing');
```
