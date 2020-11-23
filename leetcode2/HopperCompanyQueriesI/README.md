# Problem

[Hopper Company Queries I](https://leetcode.com/problems/hopper-company-queries-i/)

# Implementation

```sql
SELECT t.month,
       COUNT(DISTINCT driver_id) active_drivers,
       COUNT(DISTINCT r.ride_id) accepted_rides
  FROM (
    (SELECT 1 AS month) 
      UNION (SELECT 2 AS month)
      UNION (SELECT 3 AS month)
      UNION (SELECT 4 AS month)
      UNION (SELECT 5 AS month)
      UNION (SELECT 6 AS month)
      UNION (SELECT 7 AS month)
      UNION (SELECT 8 AS month)
      UNION (SELECT 9 AS month)
      UNION (SELECT 10 AS month)
      UNION (SELECT 11 AS month)
      UNION (SELECT 12 AS month)      
  ) t
LEFT JOIN (
) d
  ON d.month <= t.month
LEFT JOIN (
) r
  ON t.month = r.month
GROUP BY t.month
ORDER BY t.month;
```

```sql
SELECT t.month,
       COUNT(DISTINCT driver_id) active_drivers,
       COUNT(DISTINCT r.ride_id) accepted_rides
  FROM (
    (SELECT 1 AS month) 
      UNION (SELECT 2 AS month)
      UNION (SELECT 3 AS month)
      UNION (SELECT 4 AS month)
      UNION (SELECT 5 AS month)
      UNION (SELECT 6 AS month)
      UNION (SELECT 7 AS month)
      UNION (SELECT 8 AS month)
      UNION (SELECT 9 AS month)
      UNION (SELECT 10 AS month)
      UNION (SELECT 11 AS month)
      UNION (SELECT 12 AS month)      
  ) t
LEFT JOIN (
  SELECT driver_id,
         (CASE WHEN YEAR(join_date) = 2019 
               THEN '1' 
               ELSE month(join_date) 
           END) AS `month`
    FROM Drivers
   WHERE YEAR(join_date) <= 2020
) d
  ON d.month <= t.month
LEFT JOIN (
) r
  ON t.month = r.month
GROUP BY t.month
ORDER BY t.month;
```


```sql
-- 1689ms 20.27% 0B 100.00%
SELECT t.month,
       COUNT(DISTINCT driver_id) active_drivers,
       COUNT(DISTINCT r.ride_id) accepted_rides
  FROM (
    (SELECT 1 AS month) 
      UNION (SELECT 2 AS month)
      UNION (SELECT 3 AS month)
      UNION (SELECT 4 AS month)
      UNION (SELECT 5 AS month)
      UNION (SELECT 6 AS month)
      UNION (SELECT 7 AS month)
      UNION (SELECT 8 AS month)
      UNION (SELECT 9 AS month)
      UNION (SELECT 10 AS month)
      UNION (SELECT 11 AS month)
      UNION (SELECT 12 AS month)      
  ) t
LEFT JOIN (
  SELECT driver_id,
         (CASE WHEN YEAR(join_date) = 2019 
               THEN '1' 
               ELSE month(join_date) 
           END) AS `month`
    FROM Drivers
   WHERE YEAR(join_date) <= 2020
) d
  ON d.month <= t.month
LEFT JOIN (
  SELECT MONTH(requested_at) AS 'month', a.ride_id
    FROM AcceptedRides a
    JOIN Rides rr
      ON rr.ride_id = a.ride_id
   WHERE YEAR(requested_at) = 2020
) r
  ON t.month = r.month
GROUP BY t.month
ORDER BY t.month;
```
