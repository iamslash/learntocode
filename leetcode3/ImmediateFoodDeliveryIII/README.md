# Problem

[Immediate Food Delivery III](https://leetcode.com/problems/immediate-food-delivery-iii/)

# Implementation

```sql
-- 1422ms 5.77% 0B 100.00%
  SELECT order_date,
         ROUND(SUM(order_date = customer_pref_delivery_date) / 
           COUNT(delivery_id) * 100, 2) AS immediate_percentage
    FROM Delivery
GROUP BY order_date
ORDER BY order_date ASC

-- 878ms 100.00% 0B 100.00%
  SELECT DISTINCT order_date,
         ROUND(SUM(CASE WHEN order_date = customer_pref_delivery_date THEN 1 ELSE 0 END) / 
           COUNT(delivery_id) * 100, 2) AS immediate_percentage
    FROM Delivery
GROUP BY order_date
ORDER BY order_date ASC

```
