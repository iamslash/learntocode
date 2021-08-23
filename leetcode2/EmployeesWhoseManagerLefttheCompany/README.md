# Problem

[Employees Whose Manager Left the Company](https://leetcode.com/problems/employees-whose-manager-left-the-company/)

# Implementation

```sql
-- 326ms 36.21% 0B 100.00%
  SELECT employee_id 
    FROM Employees
   WHERE salary < 30000 AND
         manager_id IS NOT NULL AND
         manager_id NOT IN (SELECT employee_id FROM Employees)
ORDER BY employee_id ASC;


-- 259ms 91.38% 0B 100.00%
   SELECT e1.employee_id 
     FROM Employees AS e1
LEFT JOIN Employees AS e2
       ON e1.manager_id = e2.employee_id
    WHERE e1.manager_id IS NOT NULL AND
          e2.employee_id is null AND
          e1.salary < 30000
 ORDER BY e1.employee_id ASC;
```
