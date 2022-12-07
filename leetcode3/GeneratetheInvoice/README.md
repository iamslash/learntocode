# Problem

[Generate the Invoice](https://leetcode.com/problems/generate-the-invoice/)

# Implementation

```sql
-- 1080ms 50.70% 0B 100.00%
WITH
A AS (
    SELECT invoice_id, 
           product_id, 
           quantity, 
           quantity * price AS price
      FROM Purchases 
INNER JOIN Products USING(product_id)
),
B AS (
    SELECT invoice_id,
           SUM(price) AS total
      FROM A
  GROUP BY invoice_id
),
C AS (
    SELECT invoice_id,
           RANK() OVER(ORDER BY total DESC, invoice_id) AS rnk
      FROM B
),
D AS (
    SELECT invoice_id 
      FROM C 
     WHERE rnk = 1
)
    SELECT product_id, 
           quantity, 
           price
      FROM A a
INNER JOIN D d USING(invoice_id)
```

```sql
-- 886ms 80.90% 0B 100.00%
WITH
A AS (
    SELECT invoice_id, 
           product_id, 
           quantity, 
           quantity * price AS price
      FROM Purchases 
INNER JOIN Products USING(product_id)
),
B AS (
    SELECT invoice_id,
           SUM(price) AS total
      FROM A
  GROUP BY invoice_id
),
C AS (
    SELECT invoice_id 
      FROM B
  ORDER BY total DESC, invoice_id ASC
     LIMIT 1
)
    SELECT product_id, 
           quantity, 
           price
      FROM A
INNER JOIN C USING(invoice_id)
```
