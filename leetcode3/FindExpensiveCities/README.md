# Problem

[Find Expensive Cities](https://leetcode.com/problems/find-expensive-cities/)

# Implementation

```sql
-- 535ms 0B
SELECT city
  FROM Listings
 GROUP BY city
HAVING AVG(Price) > (SELECT AVG(price) FROM Listings)
 ORDER BY city
```
