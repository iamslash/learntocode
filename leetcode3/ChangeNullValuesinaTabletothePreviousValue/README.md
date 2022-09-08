# Problem

[Change Null Values in a Table to the Previous Value](https://leetcode.com/problems/change-null-values-in-a-table-to-the-previous-value/)

# Implementation

```sql
-- difficult
-- 442ms 75.79% 0B 100.00%
WITH cte AS (
  SELECT id,
         drink,
         ROW_NUMBER() OVER() AS ord 
    FROM CoffeeShop),
     cte2 AS (
  SELECT id,
         drink,
         ord,
         SUM(1 - ISNULL(drink)) OVER(ORDER BY ord) AS group_id
    FROM cte)

  SELECT id,
         FIRST_VALUE(drink) OVER(PARTITION BY group_id) AS drink
    FROM cte2
ORDER BY ord;
```
