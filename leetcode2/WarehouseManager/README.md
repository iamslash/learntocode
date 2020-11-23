# Problem

[Warehouse Manager](https://leetcode.com/problems/warehouse-manager/)

# Implementation

```
-- 595ms 22.86% 0B 100.00%
SELECT w.name AS warehouse_name, 
       SUM(p.Width * p.Length * p.Height * w.units) AS volume
FROM Warehouse w
JOIN Products p
  ON w.product_id = p.product_id
GROUP BY w.name
```
