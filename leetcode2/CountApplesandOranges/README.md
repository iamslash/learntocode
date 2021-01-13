# Problem

[Count Apples and Oranges](https://leetcode.com/problems/count-apples-and-oranges/)

# Implementation

```sql
-- 659ms 97.91% 0B 100.00%
SELECT SUM(apple_count) as apple_count,
       SUM(orange_count) as orange_count
  FROM ((SELECT SUM(c.apple_count) AS apple_count,
                SUM(c.orange_count) AS orange_count
           FROM boxes b
      LEFT JOIN chests c
             ON b.chest_id = c.chest_id
          WHERE b.chest_id is not null)
  UNION (SELECT SUM(b.apple_count) AS apple_count,
                SUM(b.orange_count) AS orange_count
          FROM boxes b)) AS t
```
