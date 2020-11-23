# Problem

[The Most Frequently Ordered Products for Each Customer](https://leetcode.com/problems/the-most-frequently-ordered-products-for-each-customer/)

# Implementation

```sql
SELECT customer_id, product_id, product_name
FROM () tmp
WHERE rnk = 1
ORDER BY customer_id, product_id
```

```sql
-- 1929ms 100.00% 0B 100.00%
SELECT customer_id, product_id, product_name
FROM (
  SELECT o.customer_id, o.product_id, p.product_name,
  RANK() OVER(
    PARTITION BY customer_id 
    ORDER BY COUNT(o.product_id) DESC
  ) AS rnk
  FROM Orders o
  JOIN Products p
  ON o.product_id = p.product_id
  GROUP BY customer_id, product_id
) tmp
WHERE rnk = 1
ORDER BY customer_id, product_id;
```
