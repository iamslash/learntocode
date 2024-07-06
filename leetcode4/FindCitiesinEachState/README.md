# Problem

[Find Cities in Each State](https://leetcode.com/problems/find-cities-in-each-state/)

# Implementation

```sql
-- 325ms 15.38% 0B 100.00%
SELECT state,
       GROUP_CONCAT(city ORDER BY city SEPARATOR ', ') AS cities
  FROM cities
 GROUP BY state
 ORDER BY state;
```
