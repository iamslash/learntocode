# Problem

[Symmetric Coordinates](https://leetcode.com/problems/symmetric-coordinates/)

# Implementation

```sql
-- 550ms 100.00% 0B 100.00%
SELECT DISTINCT c1.x, 
                c1.y
  FROM Coordinates c1 
  JOIN Coordinates c2
    ON (c1.x = c2.y AND c1.y = c2.x AND c1.x < c1.y)
 
 UNION

SELECT x, x
  FROM Coordinates
 WHERE x = y
 GROUP BY x
HAVING COUNT(x) > 1
 ORDER BY x, y 
```
