# Problem

> [Orders With Maximum Quantity Above Average](https://leetcode.com/problems/orders-with-maximum-quantity-above-average/)

# Implementation

```sql
-- 527ms 100.00% 0B 100.00%
  SELECT order_id
    FROM OrdersDetails
GROUP BY order_id
  HAVING MAX(quantity) > (
    SELECT MAX(avg_qty) 
      FROM (SELECT order_id, 
                   SUM(quantity)/COUNT(product_id) AS avg_qty
              FROM OrdersDetails
          GROUP BY order_id) t)
```

```sql
-- 581ms 100.00% 0B 100.00%
WITH t AS (
  SELECT order_id,
         AVG(quantity) AS avg_qty,
         MAX(quantity) AS max_qty
    FROM OrdersDetails
GROUP BY order_id)

SELECT order_id
  FROM t
 WHERE max_qty > (SELECT MAX(avg_qty)
                    FROM t)
```
