# Problem

[Find Latest Salaries](https://leetcode.com/problems/find-latest-salaries/)

# Implementation

```sql
-- 1515ms 100.00% 0B 100.00%
  SELECT emp_id,
         firstname,
         lastname,
         MAX(salary) AS salary,
         department_id
    FROM Salary
GROUP BY emp_id
ORDER BY emp_id ASC;

```

```sql
-- 1428ms 100.00% 0B 100.00%
  SELECT distinct emp_id,
         firstname,
         lastname,
         MAX(salary) OVER (PARTITION BY emp_id) AS salary,
         department_id
    FROM Salary;
```
