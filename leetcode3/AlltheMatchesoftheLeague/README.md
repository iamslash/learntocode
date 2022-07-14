# Problem

[All the Matches of the League](https://leetcode.com/problems/all-the-matches-of-the-league/)

# Implementation

```sql
// 621ms 100.00% 0B 100.00%
SELECT a.team_name AS home_team, 
       b.team_name AS away_team
  FROM Teams a
  JOIN Teams b
    ON a.team_name != b.team_name;       
```
