# Problem

[Game Play Analysis V](https://leetcode.com/problems/game-play-analysis-v/)

```
SQL Schema
Table: Activity

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| player_id    | int     |
| device_id    | int     |
| event_date   | date    |
| games_played | int     |
+--------------+---------+
(player_id, event_date) is the primary key of this table.
This table shows the activity of players of some game.
Each row is a record of a player who logged in and played a number of games (possibly 0) before logging out on some day using some device.
```

```
Activity table:
+-----------+-----------+------------+--------------+
| player_id | device_id | event_date | games_played |
+-----------+-----------+------------+--------------+
| 1         | 2         | 2016-03-01 | 5            |
| 1         | 2         | 2016-03-02 | 6            |
| 2         | 3         | 2017-06-25 | 1            |
| 3         | 1         | 2016-03-01 | 0            |
| 3         | 4         | 2016-07-03 | 5            |
+-----------+-----------+------------+--------------+

Result table:
+------------+----------+----------------+
| install_dt | installs | Day1_retention |
+------------+----------+----------------+
| 2016-03-01 | 2        | 0.50           |
| 2017-06-25 | 1        | 0.00           |
+------------+----------+----------------+
Player 1 and 3 installed the game on 2016-03-01 but only player 1 logged back in on 2016-03-02 so the day 1 retention of 2016-03-01 is 1 / 2 = 0.50
Player 2 installed the game on 2017-06-25 but didn't log back in on 2017-06-26 so the day 1 retention of 2017-06-25 is 0 / 1 = 0.00
```

# Implementation

```sql
SELECT 
  install_dt, 
  COUNT(player_id) AS installs,
  ROUND(COUNT(next_day) / COUNT(player_id), 2) AS Day1_retention
FROM () AS t
GROUP BY install_dt;
```

```sql
SELECT 
  install_dt, 
  COUNT(player_id) AS installs,
  ROUND(COUNT(next_day) / COUNT(player_id), 2) AS Day1_retention
FROM (
  SELECT a1.player_id, a1.install_dt, a2.event_date AS next_day
  FROM () AS a1
  LEFT JOIN Activity AS a2
    ON a1.player_id = a2.player_id AND
      a2.event_date = a1.install_dt + 1
) AS t
GROUP BY install_dt;
```

```sql
-- 988ms 35.21% 0B 100.00%
SELECT 
  install_dt, 
  COUNT(player_id) AS installs,
  ROUND(COUNT(next_day) / COUNT(player_id), 2) AS Day1_retention
FROM (
  SELECT a1.player_id, a1.install_dt, a2.event_date AS next_day
  FROM (
    SELECT player_id, MIN(event_date) AS install_dt
    FROM Activity
    GROUP BY player_id
  ) AS a1
  LEFT JOIN Activity AS a2
    ON a1.player_id = a2.player_id AND
      a2.event_date = a1.install_dt + 1
) AS t
GROUP BY install_dt;
```
