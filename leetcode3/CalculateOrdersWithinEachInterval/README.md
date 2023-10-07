# Problem

[Calculate Orders Within Each Interval](https://leetcode.com/problems/calculate-orders-within-each-interval/)

# Implementation

```sql
-- 506ms 100.00% 0B 100.00%
SELECT (((minute - 1) div 6) + 1) interval_no,
       SUM(order_count) total_orders
  FROM orders
 GROUP BY interval_no
 ORDER BY interval_no
```
