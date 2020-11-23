# Problem

[Sellers With No Sales](https://leetcode.com/problems/sellers-with-no-sales/)

# Implementation

```sql
SELECT DISTINCT seller_name
FROM seller s
WHERE seller_id NOT IN ()
ORDER BY 1 ASC
```

```sql
-- 824ms 100.00% 0B 100.00%
SELECT DISTINCT seller_name
FROM seller s
WHERE seller_id NOT IN (
  SELECT DISTINCT seller_id
  FROM orders
  WHERE YEAR(sale_date) = 2020
)
ORDER BY 1 ASC
```
