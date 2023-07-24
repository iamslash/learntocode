# Problem

[Flight Occupancy and Waitlist Analysis](https://leetcode.com/problems/flight-occupancy-and-waitlist-analysis/)

# Implementation

```sql
   SELECT f.flight_id AS flight_id,
          LEAST() AS booked_cnt,
          IF() AS waitlist_cnt
     FROM Flights f
LEFT JOIN Passengers p
       ON f.flight_id = p.flight_id
 GROUP BY f.flight_id    
 ORDER BY f.flight_id ASC


-- 1699ms 98.08% 0B 100.00%
   SELECT f.flight_id AS flight_id,
          LEAST(f.capacity, COUNT(p.flight_id)) AS booked_cnt,
          IF(COUNT(p.flight_id) > f.capacity, 
             COUNT(p.flight_id) - f.capacity, 
             0) AS waitlist_cnt
     FROM Flights f
LEFT JOIN Passengers p
       ON f.flight_id = p.flight_id
 GROUP BY f.flight_id    
 ORDER BY f.flight_id ASC

```
