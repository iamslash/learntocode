# Problem

[Find the Missing IDs](https://leetcode.com/problems/find-the-missing-ids/)

# Implementation

```sql
-- 342ms 100.00% 0B 100.00%
WITH recursive t as (
    SELECT 1 AS i
     UNION ALL
    SELECT i + 1
      FROM t
     WHERE i < (SELECT MAX(customer_id) from customers)
)
   SELECT t.i AS ids 
     from t
LEFT JOIN customers c 
       ON c.customer_id = t.i
    WHERE c.customer_id is null
```
