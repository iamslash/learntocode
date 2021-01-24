# Problem

[The Number of Employees Which Report to Each Employee](https://leetcode.com/problems/the-number-of-employees-which-report-to-each-employee/)

# Implementation

```sql
-- 712ms 17.24% 0B 100.00%
  SELECT a.employee_id AS employee_id,
         a.name AS name,
         COUNT(a.employee_id) AS reports_count,
         ROUND(AVG(b.age)) AS average_age
    FROM Employees a
    JOIN Employees b ON a.employee_id = b.reports_to
GROUP BY a.employee_id
ORDER BY a.employee_id
```
