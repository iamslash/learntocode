# Problem

[Consecutive Available Seats II](https://leetcode.com/problems/consecutive-available-seats-ii/)

# Implementation

```sql
-- 514ms 96.83% 0B 100.00%
WITH cte AS (
  SELECT seat_id,
         seat_id - ROW_NUMBER() OVER(ORDER BY seat_id) AS r1
    FROM Cinema
   WHERE free = 1),
cte1 AS (   
  SELECT r1,
         COUNT(*) AS consecutive_seats_len,
         MAX(seat_id) AS last_seat_id,
         MIN(seat_id) as first_seat_id
    FROM cte
   GROUP BY r1)
SELECT first_seat_id,
       last_seat_id,
       consecutive_seats_len
  FROM cte1
 WHERE consecutive_seats_len = (SELECT MAX(consecutive_seats_len) FROM cte1) 
```
