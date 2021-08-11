# Problem

[Employees With Missing Information](https://leetcode.com/problems/employees-with-missing-information/)

# Implementation

```sql
-- 1072ms 5.41% 0B 100.00%
SELECT DISTINCT employee_id
FROM (
   SELECT e.employee_id AS employee_id
     FROM Employees e
LEFT JOIN Salaries s
       ON e.employee_id = s.employee_id
    WHERE s.salary is null
UNION ALL
   SELECT s.employee_id AS employee_id
     FROM Employees e
RIGHT JOIN Salaries s
       ON e.employee_id = s.employee_id
    WHERE e.name is null
) t
ORDER BY employee_id    
```

```sql
-- 452ms 57.66% 0B 100.00%
  SELECT employee_id 
    FROM Employees
   WHERE employee_id NOT IN (SELECT employee_id FROM Salaries)
   UNION 
  SELECT employee_id 
    FROM Salaries
   WHERE employee_id NOT IN (SELECT employee_id FROM Employees)
ORDER BY employee_id;
```
