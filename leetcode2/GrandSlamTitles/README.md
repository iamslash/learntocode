# Problem

[Grand Slam Titles](https://leetcode.com/problems/grand-slam-titles/)

# Implementation

```sql
-- 1216ms 100.00% 0B 100.00%
SELECT player_id, 
       player_name,
       SUM(player_id = Wimbledon) +
         SUM(player_id = Fr_open) +
         SUM(player_id = US_open) +
         SUM(player_id = Au_open) AS grand_slams_count
  FROM Players
  JOIN Championships
    ON player_id = Wimbledon OR
       player_id = Fr_open OR
       player_id = US_open OR
       player_id = Au_open
 GROUP BY player_id
```
