# Problem

[Premier League Table Ranking II](https://leetcode.com/problems/premier-league-table-ranking-ii/description/)

# Implementation

```sql
-- 299ms 85.52%
WITH cte1 AS(
  SELECT team_id, 
         team_name,
         wins * 3 + draws * 1 AS points
    FROM TeamStats),
cte2 AS(
  SELECT *,
         RANK() OVER(ORDER BY points DESC) as position,
         COUNT(*) OVER() AS total_teams
    FROM cte1)
SELECT team_name,
       points,
       position,
       CASE 
         WHEN position <= CEIL(total_teams/3.0) THEN 'Tier 1'
         WHEN position <= CEIL(2 * total_teams/3.0) THEN 'Tier 2'
         ELSE 'Tier 3'
       END AS tier
  FROM cte2
 ORDER BY points DESC, team_name
```
