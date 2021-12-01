# Problem

[Drop Type 1 Orders for Customers With Type 0 Orders](https://leetcode.com/problems/drop-type-1-orders-for-customers-with-type-0-orders/)

# Implementation

```sql
-- 500ms 22.01% 0B 100.00%
WITH Ranks AS (
  SELECT order_id,
         customer_id,
         order_type,
         RANK() 
           OVER(PARTITION BY customer_id ORDER BY order_type ASC) 
           AS type_rank
    FROM Orders
)
SELECT order_id, 
       customer_id, 
       order_type
  FROM Ranks
 WHERE Ranks.type_rank = 1;
```
