# Problem

[The First Day of the Maximum Recorded Degree in Each City](https://leetcode.com/problems/the-first-day-of-the-maximum-recorded-degree-in-each-city/)

# Implementation

```sql
-- 909ms 41.24% 0B 100.00%
  SELECT city_id, day, degree
    FROM (
      SELECT city_id, 
             day, 
             degree,
             ROW_NUMBER() OVER(PARTITION BY city_id
               ORDER BY degree DESC, day ASC) AS rnk
        FROM Weather
    ) a
   WHERE rnk = 1
ORDER BY city_id
```
