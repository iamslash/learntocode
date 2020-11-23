# Problem

[Game Play Analysis IV](https://leetcode.com/problems/game-play-analysis-iv/)

# Schema

```
Activity

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

# Example

```
Activity table:
+-----------+-----------+------------+--------------+
| player_id | device_id | event_date | games_played |
+-----------+-----------+------------+--------------+
| 1         | 2         | 2016-03-01 | 5            |
| 1         | 2         | 2016-03-02 | 6            |
| 2         | 3         | 2017-06-25 | 1            |
| 3         | 1         | 2016-03-02 | 0            |
| 3         | 4         | 2018-07-03 | 5            |
+-----------+-----------+------------+--------------+

Result table:
+-----------+
| fraction  |
+-----------+
| 0.33      |
+-----------+
Only the player with id 1 logged back in after the first day he had logged in so the answer is 1/3 = 0.33
```

# Iea

2 일동안 연속으로 로그인한 유저의 비율을 구하는 문제이다.

# Implementation

```sql
-- 451ms 50.20%
SELECT
  ROUND(COUNT(A2.player_id)/COUNT(A1.player_id), 2)
FROM
  (SELECT player_id, MIN(event_date) AS first_date
  FROM 
    Activity
  GROUP BY player_id) A1 
LEFT JOIN
  Activity A2 
ON
  A1.player_id = A2.player_id AND
  A1.first_date + 1 = A2.event_date
```
