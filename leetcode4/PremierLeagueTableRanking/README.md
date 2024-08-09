# Problem

[Premier League Table Ranking](https://leetcode.com/problems/premier-league-table-ranking/)

# Implementation

```sql
-- 715ms 6.06% 0B 100.00%
SELECT team_id,
       team_name,
       SUM(wins * 3 + draws) AS points,
       RANK() OVER (ORDER BY SUM(wins * 3 + draws) DESC) AS position
  FROM TeamStats       
 GROUP BY team_id
 ORDER BY points DESC, team_name ASC; 

-- 246ms 98.48 0B 100.00%
SELECT team_id,
       team_name,
       wins * 3 + draws AS points,
       RANK() OVER (ORDER BY wins * 3 + draws DESC) AS position
  FROM TeamStats       
 ORDER BY points DESC, team_name ASC; 
```
