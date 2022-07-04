# Problem

[Product Sales Analysis IV](https://leetcode.com/problems/product-sales-analysis-iv/)

# Implementation

```sql
-- 1295ms 33.64% 0B 100.00%
SELECT user_id,
       product_id
  FROM (
    SELECT s.product_id,
           s.user_id,
           SUM(s.quantity * p.price) AS amt,
           RANK() OVER(PARTITION BY s.user_id ORDER BY SUM(s.quantity * p.price) DESC) AS rnk
      FROM Sales s
      JOIN Product p
        ON s.product_id = p.product_id
  GROUP BY s.user_id, s.product_id) t
WHERE rnk = 1;
```
