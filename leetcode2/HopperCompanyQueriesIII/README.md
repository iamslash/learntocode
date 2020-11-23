# Problem

[Hopper Company Queries III](https://leetcode.com/problems/hopper-company-queries-iii/)

# Implementation

```sql
-- 1219ms 64.17% 0B 100.00%
WITH RECURSIVE cte_month AS (
  SELECT 1 AS month
  UNION ALL
  SELECT month+1 
  FROM cte_month 
  where month < 10
),
cte_rides AS (
  select month(requested_at) month, ride_distance, ride_duration
  from AcceptedRides a
  join Rides r
  on a.ride_id = r.ride_id
  where year(requested_at) = 2020
)
select cte_month.month, 
       round(ifnull(sum(ride_distance)/3,0),2) average_ride_distance,
       round(ifnull(sum(ride_duration)/3,0),2) average_ride_duration
from cte_month
left join cte_rides
on cte_rides.month - cte_month.month between 0 and 2
group by cte_month.month
```
