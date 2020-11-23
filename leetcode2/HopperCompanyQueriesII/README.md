# Problem

[Hopper Company Queries II](https://leetcode.com/problems/hopper-company-queries-ii/)

# Implementation

```sql
-- 1320ms 55.93% 0B 100.00%
WITH RECURSIVE 
  months AS (
    SELECT 1 AS number UNION
    SELECT number + 1
      FROM months
     WHERE number < 12),
  available_drivers AS (
    SELECT d.driver_id, (
      CASE
        WHEN YEAR(d.join_date) <= 2019 THEN 1
        ELSE MONTH(d.join_date)
      END) AS first_available_month
      FROM Drivers AS d
     WHERE d.join_date < '2021-01-01'),
  driver_accepted_ride AS (
    SELECT r.ride_id, r.requested_at, ar.driver_id
      FROM Rides AS r
      JOIN AcceptedRides AS ar
        ON ar.ride_id = r.ride_id
     WHERE YEAR(r.requested_at) = 2020)
SELECT m.number AS month,
       (CASE
         WHEN COUNT(ad.driver_id) = 0 THEN 0
         ELSE ROUND(COUNT(DISTINCT dar.driver_id) / 
                    COUNT(DISTINCT ad.driver_id) * 100,2)
        END) AS working_percentage
  FROM months AS m
  LEFT JOIN available_drivers AS ad
         ON ad.first_available_month <= m.number
  LEFT JOIN driver_accepted_ride AS dar
         ON dar.driver_id = ad.driver_id AND
            MONTH(dar.requested_at) = m.number
GROUP BY 1
ORDER BY 1 ASC;
```
