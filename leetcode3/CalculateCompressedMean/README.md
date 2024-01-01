# Problem

[Calculate Compressed Mean](https://leetcode.com/problems/calculate-compressed-mean/)

# Implementation

```sql
SELECT ROUND(..., 2) AS average_itetms_per_order
  FROM Orders
  
-- 936ms 100.00% 0B 100.00%   
SELECT ROUND(SUM(item_count * order_occurrences) / SUM(order_occurrences), 2) AS average_items_per_order
  FROM Orders
```
