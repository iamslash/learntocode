# Problem

[The Number of Passengers in Each Bus I](https://leetcode.com/problems/the-number-of-passengers-in-each-bus-i/)

# Implementation

```sql
-- 1052ms 51.80% 0B 100.00%
WITH t AS (
    SELECT p.passenger_id,
           MIN(b.arrival_time) AS arrival_time
      FROM Passengers p
INNER JOIN Buses b
        ON p.arrival_time <= b.arrival_time
  GROUP BY p.passenger_id
)
   SELECT b.bus_id,
          COUNT(t.arrival_time) AS passengers_cnt
     FROM Buses b
LEFT JOIN t
       ON b.arrival_time = t.arrival_time
 GROUP BY b.bus_id
 ORDER BY b.bus_id

-- 1127ms 44.93% 0B 100.00%
WITH t AS (
  SELECT b.bus_id,
         LAG(b.arrival_time, 1, -1) OVER (ORDER BY b.arrival_time) lower_bound,
         b.arrival_time AS upper_bound
    FROM Buses b
)
   SELECT T.bus_id,
          COUNT(P.passenger_id) AS passengers_cnt
     FROM t T
LEFT JOIN Passengers P 
       ON P.arrival_time > T.lower_bound AND 
          P.arrival_time <= T.upper_bound
 GROUP BY T.bus_id
 ORDER BY T.bus_id;
```
