# Problem

[Pizza Toppings Cost Analysis](https://leetcode.com/problems/pizza-toppings-cost-analysis/)

# Implementation

```sql
-- 502ms 89.44% 0B 100.00%
WITH cte1 AS (
  SELECT A.topping_name AS a,
         B.topping_name AS b,
         C.topping_name AS c,
         ROUND(A.cost + B.cost + C.cost, 2) AS cost
    FROM Toppings A, 
         Toppings B, 
         Toppings C),
cte2 AS (
  SELECT CONCAT(a, ",", b, ",", c) as pizza,
         cost as total_cost
    FROM cte1
   WHERE a < b AND b < c
   ORDER BY cost DESC,
            pizza ASC)
SELECT * from cte2;
```
