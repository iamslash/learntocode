# Problem

[Product's Worth Over Invoices](https://leetcode.com/problems/products-worth-over-invoices/)

# Implementation

```sql
-- 591ms 100.00% 0B 100.00%
   SELECT p.name AS name,
          SUM(i.rest) AS rest,
          SUM(i.paid) AS paid,
          SUM(i.canceled) AS canceled,
          SUM(i.refunded) AS refunded
     FROM Product p
     JOIN Invoice i 
       ON p.product_id = i.product_id
 GROUP BY p.name
 ORDER BY p.name ASC
```
