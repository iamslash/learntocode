# Problem

[Team Scores in Football Tournament](https://leetcode.com/problems/team-scores-in-football-tournament/)

# Idea

* Schema

```
Teams table:

+---------------+----------+
| Column Name   | Type     |
+---------------+----------+
| team_id       | int      |
| team_name     | varchar  |
+---------------+----------+
team_id is the primary key of this table.
Each row of this table represents a single football team.

Matches table:

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| match_id      | int     |
| host_team     | int     |
| guest_team    | int     | 
| host_goals    | int     |
| guest_goals   | int     |
+---------------+---------+
match_id is the primary key of this table.
Each row is a record of a finished match between two different teams. 

Teams host_team and guest_team are represented by their IDs in the
teams table (team_id) and they scored host_goals and guest_goals goals
respectively.
```

* Result
  
```
  Teams table:
+-----------+--------------+
| team_id   | team_name    |
+-----------+--------------+
| 10        | Leetcode FC  |
| 20        | NewYork FC   |
| 30        | Atlanta FC   |
| 40        | Chicago FC   |
| 50        | Toronto FC   |
+-----------+--------------+

Matches table:
+------------+--------------+---------------+-------------+--------------+
| match_id   | host_team    | guest_team    | host_goals  | guest_goals  |
+------------+--------------+---------------+-------------+--------------+
| 1          | 10           | 20            | 3           | 0            |
| 2          | 30           | 10            | 2           | 2            |
| 3          | 10           | 50            | 5           | 1            |
| 4          | 20           | 30            | 1           | 0            |
| 5          | 50           | 30            | 1           | 0            |
+------------+--------------+---------------+-------------+--------------+

Result table:
+------------+--------------+---------------+
| team_id    | team_name    | num_points    |
+------------+--------------+---------------+
| 10         | Leetcode FC  | 7             |
| 20         | NewYork FC   | 3             |
| 50         | Toronto FC   | 3             |
| 30         | Atlanta FC   | 1             |
| 40         | Chicago FC   | 0             |
+------------+--------------+---------------+
```

# Implementation

Left Outer Join, Summation grouped by

```sql
# Write your MySQL query statement below
# 869ms 71.83% 0B 100.00%
SELECT team_id, team_name,
  SUM(CASE WHEN team_id=host_team AND host_goals > guest_goals THEN 3 ELSE 0 END) +
  SUM(CASE WHEN team_id=guest_team AND guest_goals > host_goals THEN 3 ELSE 0 END) +
  SUM(CASE WHEN team_id=host_team AND host_goals = guest_goals THEN 1 ELSE 0 END) +
  SUM(CASE WHEN team_id=guest_team AND guest_goals = host_goals THEN 1 ELSE 0 END)
  AS num_points
FROM Teams
LEFT JOIN Matches
ON team_id = host_team OR team_id=guest_team
GROUP BY team_id
ORDER BY num_points DESC, team_id ASC;
```
