# Problem

[Primary Department for Each Employee](https://leetcode.com/problems/primary-department-for-each-employee/)

# Implementation

```sql
-- 436ms 100.00% 0B 100.00%
  SELECT employee_id, 
         department_id
    FROM Employee
   WHERE primary_flag = 'Y'
   UNION
  SELECT employee_id,
         department_id
    FROM employee
GROUP BY employee_id
  HAVING COUNT(employee_id) = 1
```
