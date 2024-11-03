# Problem

[Second Highest Salary II](https://leetcode.com/problems/second-highest-salary-ii/)

# Implementation

```sql
WITH cte AS (
  SELECT emp_id,
         dept,
         DENSE_RANK() OVER() AS rnk
    FROM employees)
SELECT emp_id,
       dept
  FROM cte
 WHERE rnk = 2
 ORDER BY 1;
```

```sql
-- 350ms 44.34% 0B 100.00%
WITH cte AS (
  SELECT emp_id,
         dept,
         DENSE_RANK() OVER(PARTITION BY dept ORDER BY salary DESC) AS rnk
    FROM employees)
SELECT emp_id,
       dept
  FROM cte
 WHERE rnk = 2
 ORDER BY 1;
```
