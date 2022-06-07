# Problem

[Products With Three or More Orders in Two Consecutive Years](https://leetcode.com/problems/products-with-three-or-more-orders-in-two-consecutive-years/)

# Implementation

```sql
-- 601ms 46.34% 0B 100.00%
-- window function
SELECT DISTINCT d.product_id
  FROM (SELECT product_id,
               YEAR(purchase_date) AS curr_year,
               LEAD(YEAR(purchase_date)) OVER(PARTITION BY product_id ORDER BY YEAR(purchase_date)) AS next_year
          FROM orders
      GROUP BY curr_year, product_id
        HAVING COUNT(order_id) >= 3
  ) d
 WHERE d.next_year = d.curr_year + 1
```

```sql
-- 627ms 37.81% 0B 100.00%
-- cte
WITH cte AS(SELECT product_id,
                   YEAR(purchase_date) AS purchase_year
              FROM orders
          GROUP BY purchase_year, product_id
            HAVING COUNT(order_id) >=3)
SELECT DISTINCT c1.product_id
  FROM cte c1
  JOIN cte c2
    ON c1.product_id = c2.product_id AND
       c1.purchase_year = c2.purchase_year + 1
```
