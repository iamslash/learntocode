# Problem

[Calculate Parking Fees and Duration](https://leetcode.com/problems/calculate-parking-fees-and-duration/)

# Implementation

```
-- 297ms 97.04% 0B 100.00%
WITH cte AS (
  SELECT lot_id,
         car_id,
         SUM(fee_paid) AS sum_fee,
         SUM(TIMESTAMPDIFF(second, entry_time, exit_time) / 60 / 60) AS sum_hour,
         RANK() OVER (
           PARTITION BY car_id
           ORDER BY SUM(TIMESTAMPDIFF(second, entry_time, exit_time) / 60 / 60) DESC
         ) AS rnk
    FROM parkingtransactions
   GROUP BY 1, 2 
)
    SELECT a.car_id,
           SUM(a.sum_fee) AS total_fee_paid,
           ROUND(SUM(a.sum_fee) / SUM(a.sum_hour), 2) AS avg_hourly_fee,
           b.lot_id AS most_time_lot
      FROM cte AS a
INNER JOIN (
        SELECT car_id,
               lot_id
          FROM cte
         WHERE rnk = 1 
      ) AS b
    ON a.car_id = b.car_id
 GROUP BY 1, 4
 ORDER BY 1;
```

















