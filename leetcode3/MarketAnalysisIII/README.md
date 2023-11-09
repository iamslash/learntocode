# Problem

[Market Analysis III](https://leetcode.com/problems/market-analysis-iii/)

# Implementation

```sql
WITH cte AS (
)
SELECT * 
  FROM cte
 WHERE num_items = (
   SELECT MAX(num_items)
     FROM cte
 );
```

```sql
-- 1299ms 81.03% 0B 100.00%
WITH cte AS (
   SELECT o.seller_id,
          COUNT(DISTINCT i.item_id) num_items
     FROM Orders o
LEFT JOIN Items i
    USING (item_id)
LEFT JOIN Users u
    USING (seller_id)
    WHERE i.item_brand <> u.favorite_brand
    GROUP BY 1
    ORDER BY 2 DESC
)
SELECT * 
  FROM cte
 WHERE num_items = (
   SELECT MAX(num_items)
     FROM cte
 );
```
