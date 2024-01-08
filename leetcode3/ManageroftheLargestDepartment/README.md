# Problem

[Manager of the Largest Department](https://leetcode.com/problems/manager-of-the-largest-department/)

# Implementation

```sql
SELECT emp_name AS manager_name, 
       dep_id
  FROM () t
 WHERE rnk = 1 AND position = 'Manger'
 ORDER BY 2
 
SELECT emp_name AS manager_name, 
       dep_id
  FROM () t
 WHERE rnk = 1 AND position = 'Manger'
 ORDER BY 2

```

```sql
WITH Employee_Count AS (
  SELECT dep_id,
         COUNT(*) AS c
    FROM Employees
   GROUP BY dep_id)
SELECT a.emp_name AS manager_name,
       a.dep_id 
  FROM Employee a, Employee_Count b
 WHERE a.dep_id = b.dep_id AND
       a.position = 'Manager' AND
       b.c = (SELECT MAX(c) FROM Employee_Count)
 ORDER BY dep_id
```
