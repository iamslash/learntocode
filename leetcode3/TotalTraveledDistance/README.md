# Problem

[Total Traveled Distance](https://leetcode.com/problems/total-traveled-distance/)

# Implementation

```sql
-- 1195ms 100.00% 0B 100.00%
   SELECT u.user_id,
          u.name,
          IFNULL(SUM(r.distance), 0) AS "traveled distance"
     FROM Users u
LEFT JOIN Rides r
       ON u.user_id = r.user_id
 GROUP BY u.user_id
 ORDER BY u.user_id ASC;
```
