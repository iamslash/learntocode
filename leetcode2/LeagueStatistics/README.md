# Problem

> [League Statistics](https://leetcode.com/problems/league-statistics/)

# Implementation

```sql
SELECT team_name, 
       matches_played, 
       points,
       goal_for,
       goal_against,
       goal_for - goal_against AS goal_diff
  FROM Teams t2 
  JOIN (SELECT team_id,
               SUM(team_id IN (away_team_id, home_team_id)) AS matches_played,
               SUM() AS points,
               SUM() AS goal_for,
               SUM() AS goal_against
          FROM Matches m
          JOIN Teams 
            ON (team_id IN (away_team_id, home_team_id))
      GROUP BY team_id
  ) AS t1 USING(team_id)
ORDER BY points DESC,
         goal_diff DESC,
         team_name ASC
```

```sql
SELECT team_name, 
       matches_played, 
       points,
       goal_for,
       goal_against,
       goal_for - goal_against AS goal_diff
  FROM Teams t2 
  JOIN (SELECT team_id,
               SUM(team_id IN (away_team_id, home_team_id)) AS matches_played,
               SUM(CASE
                     WHEN team_id = away_team_id AND home_team_goals > away_team_goals THEN 0
                     WHEN team_id = away_team_id AND home_team_goals < away_team_goals THEN 3
                     WHEN team_id = home_team_id AND home_team_goals > away_team_goals THEN 3
                     WHEN team_id = home_team_id AND home_team_goals < away_team_goals THEN 0
                     ELSE 1
                   END) AS points,
               SUM(CASE
                     WHEN team_id = away_team_id THEN away_team_goals
                     WHEN team_id = home_team_id THEN home_team_goals
                     ELSE 0
                   END) AS goal_for,
               SUM(CASE
                     WHEN team_id = away_team_id THEN home_team_goals
                     WHEN team_id = home_team_id THEN away_team_goals
                     ELSE 0
                   END) AS goal_against
          FROM Matches m
          JOIN Teams 
            ON (team_id IN (away_team_id, home_team_id))
      GROUP BY team_id
  ) AS t1 USING(team_id)
ORDER BY points DESC,
         goal_diff DESC,
         team_name ASC
```
