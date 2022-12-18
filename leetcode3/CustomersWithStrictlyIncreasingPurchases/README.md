# Problem

[Customers With Strictly Increasing Purchases](https://leetcode.com/problems/customers-with-strictly-increasing-purchases/)

# Implementation

```
Orders table:
+----------+-------------+------------+-------+
| order_id | customer_id | order_date | price |
+----------+-------------+------------+-------+
| 1        | 1           | 2019-07-01 | 1100  |
| 2        | 1           | 2019-11-01 | 1200  |
| 3        | 1           | 2020-05-26 | 3000  |
| 4        | 1           | 2021-08-31 | 3100  |
| 5        | 1           | 2022-12-07 | 4700  |
| 6        | 2           | 2015-01-01 | 700   |
| 7        | 2           | 2017-11-07 | 1000  |
| 8        | 3           | 2017-01-01 | 900   |
| 9        | 3           | 2018-11-07 | 900   |
+----------+-------------+------------+-------+

WITH yearly AS (
   SELECT customer_id,
          YEAR(MAX(order_date)) year,
          SUM(price) price
     FROM orders
 GROUP BY YEAR(order_date), customer_id)
 
+-------------+------+-------+
| customer_id | year | price |
+-------------+------+-------+
| 1           | 2019 | 2300  |
| 1           | 2020 | 3000  |
| 1           | 2021 | 3100  |
| 1           | 2022 | 4700  |
| 2           | 2015 | 700   |
| 2           | 2017 | 1000  |
| 3           | 2017 | 900   |
| 3           | 2018 | 900   |
+-------------+------+-------+

WITH yearly AS (
   SELECT customer_id,
          YEAR(MAX(order_date)) year,
          SUM(price) price
     FROM orders
 GROUP BY YEAR(order_date), customer_id)

   SELECT y1.customer_id
     FROM yearly y1
LEFT JOIN yearly y2
       ON y1.customer_id = y2.customer_id AND
          y1.year + 1 = y2.year AND
          y1.price < y2.price

+-------------+------+-------++-------------+------+-------+
| customer_id | year | price || customer_id | year | price |
+-------------+------+-------++-------------+------+-------+
| 1           | 2019 | 2300  || 1           | 2020 | 3000  |
| 1           | 2020 | 3000  || 1           | 2021 | 3100  |
| 1           | 2021 | 3100  || 1           | 2022 | 4700  |
| 1           | 2022 | 4700  || NULL        |      |       |
| 2           | 2015 | 700   || NULL        |      |       |
| 2           | 2017 | 1000  || NULL        |      |       |
| 3           | 2017 | 900   || NULL        |      |       |
| 3           | 2018 | 900   || NULL        |      |       |
+-------------+------+-------++-------------+------+-------+
```

```sql
-- 879ms 33.33% 0B 100.00%
WITH yearly AS (
   SELECT customer_id,
          YEAR(MAX(order_date)) year,
          SUM(price) price
     FROM orders
 GROUP BY YEAR(order_date), customer_id)

   SELECT y1.customer_id
     FROM yearly y1
LEFT JOIN yearly y2
       ON y1.customer_id = y2.customer_id AND
          y1.year + 1 = y2.year AND
          y1.price < y2.price
 GROUP BY y1.customer_id
   HAVING COUNT(*) - COUNT(y2.customer_id) = 1         
```
