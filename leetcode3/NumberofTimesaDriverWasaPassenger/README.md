# Problem

[Number of Times a Driver Was a Passenger](https://leetcode.com/problems/number-of-times-a-driver-was-a-passenger/)

# Implementation

```sql
-- 544ms 100.00% 0B 100.00%
   SELECT a.driver_id, 
          IFNULL(COUNT(DISTINCT b.ride_id), 0) AS cnt
     FROM Rides a
LEFT JOIN Rides b  
       ON a.driver_id = b.passenger_id
 GROUP BY a.driver_id      
```
