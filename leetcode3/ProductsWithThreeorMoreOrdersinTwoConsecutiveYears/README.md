# Problem

[Products With Three or More Orders in Two Consecutive Years](https://leetcode.com/problems/products-with-three-or-more-orders-in-two-consecutive-years/)

# Implementation

```sql
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
