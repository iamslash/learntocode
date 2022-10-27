# Problem

[Employees With Deductions](https://leetcode.com/problems/employees-with-deductions/)

# Implementation

```
-- 1185ms 52.33% 0B 100.00%
   SELECT e.employee_id
     FROM employees e 
LEFT JOIN logs l
       ON e.employee_id = l.employee_id
 GROUP BY e.employee_id
   HAVING MAX(e.needed_hours) * 60 > 
          IFNULL(SUM(CEIL(TIMESTAMPDIFF(SECOND, l.in_time, l.out_time)/60)), 0);
```
