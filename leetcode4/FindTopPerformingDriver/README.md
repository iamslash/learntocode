# Problem

[Find Top Performing Driver](https://leetcode.com/problems/find-top-performing-driver/description/)

# Implementation

```sql
-- 1064ms 79.47%
WITH cte1 AS(
  SELECT fuel_type,
         v.driver_id,
         ROUND(AVG(rating), 2) AS rating,
         SUM(distance) AS distance
    FROM Trips t
    LEFT JOIN Vehicles v
      ON t.vehicle_id = v.vehicle_id
    LEFT JOIN Drivers d
      ON v.driver_id = d.driver_id
   GROUP BY fuel_type, v.driver_id
), cte2 AS(
  SELECT *,
         RANK() OVER(PARTITION BY fuel_type ORDER BY rating DESC, distance DESC) AS rnk
    FROM cte1
)
SELECT fuel_type,
       driver_id,
       rating,
       distance
  FROM cte2     
 WHERE rnk = 1;
```
