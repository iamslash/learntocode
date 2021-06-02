# Problem

[Group Employees of the Same Salary](https://leetcode.com/problems/group-employees-of-the-same-salary/)

# Implementation

```sql
-- 557ms 41.46% 0B 100.00%
  SELECT *, 
         DENSE_RANK() OVER(ORDER BY salary) team_id
    FROM Employees
   WHERE salary NOT IN(
             SELECT salary
               FROM Employees
           GROUP BY salary
             HAVING COUNT(*) = 1)
ORDER BY team_id, employee_id

-- 590ms 30.91% 0B 100.00%
with teams AS (
  SELECT salary,
         DENSE_RANK() OVER(ORDER BY salary ASC) AS rnk
    FROM Employees
GROUP BY salary HAVING COUNT(*) >= 2)

  SELECT E.employee_id, E.name, E.salary, T.rnk AS team_id
    FROM Employees E
    JOIN teams T 
      ON E.salary = T.salary
   WHERE T.rnk IS NOT NULL
ORDER BY team_id ASC, employee_id ASC 
```
