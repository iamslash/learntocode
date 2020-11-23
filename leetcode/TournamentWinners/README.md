# Problem

[Tournament Winners](https://leetcode.com/problems/tournament-winners/)

# References

* https://leetcode.com/problems/tournament-winners/discuss/384380/A-MySQL-Solution-(Explained)

# Idea

```
Table: Players

+-------------+-------+
| Column Name | Type  |
+-------------+-------+
| player_id   | int   |
| group_id    | int   |
+-------------+-------+
player_id is the primary key of this table.
Each row of this table indicates the group of each player.
Table: Matches

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| match_id      | int     |
| first_player  | int     |
| second_player | int     | 
| first_score   | int     |
| second_score  | int     |
+---------------+---------+
match_id is the primary key of this table.  Each row is a record of a
match, first_player and second_player contain the player_id of each
match.  first_score and second_score contain the number of points of
the first_player and second_player respectively.  You may assume that,
in each match, players belongs to the same group.
```

```
Players table:
+-----------+------------+
| player_id | group_id   |
+-----------+------------+
| 15        | 1          |
| 25        | 1          |
| 30        | 1          |
| 45        | 1          |
| 10        | 2          |
| 35        | 2          |
| 50        | 2          |
| 20        | 3          |
| 40        | 3          |
+-----------+------------+

Matches table:
+------------+--------------+---------------+-------------+--------------+
| match_id   | first_player | second_player | first_score | second_score |
+------------+--------------+---------------+-------------+--------------+
| 1          | 15           | 45            | 3           | 0            |
| 2          | 30           | 25            | 1           | 2            |
| 3          | 30           | 15            | 2           | 0            |
| 4          | 40           | 20            | 5           | 2            |
| 5          | 35           | 50            | 1           | 1            |
+------------+--------------+---------------+-------------+--------------+

Result table:
+-----------+------------+
| group_id  | player_id  |
+-----------+------------+ 
| 1         | 15         |
| 2         | 35         |
| 3         | 40         |
+-----------+------------+
```

플레이어들의 점수를 구한다.

```sql
SELECT first_player AS player, first_score AS score FROM Matches
UNION ALL
SELECT second_player, second_score FROM Matches
```

플레이어별로 점수의 합을 구한다.

```sql
SELECT player, sum(score) as score FROM
	(SELECT first_player as player, first_score as score FROM Matches
	UNION ALL
	SELECT second_player, second_score FROM Matches) s
GROUP BY player
```

그룹별 최대 점수를 inner join 으로 구한다.

```sql
SELECT group_id, max(score)
FROM Players,
	(SELECT player, sum(score) AS score from
		(SELECT first_player AS player, first_score AS score FROM Matches
		UNION ALL
		SELECT second_player, second_score FROM Matches) s
	GROUP BY player) PlayerScores
WHERE Players.player_id = PlayerScores.player
GROUP BY group_id
```

그룹별 최대점수를 알아냈으니 플레이어를 찾아낼 수 있다.

```sql
select group_id, player_id
from Players,
    (select player, sum(score) as score from
        (select first_player as player, first_score as score from Matches
        union all
        select second_player, second_score from Matches) s
    group by player) PlayerScores
    where Players.player_id = PlayerScores.player
        and (group_id, score) in                     # check against maximum score in each group
            (select group_id, max(score)
            from Players,
                (select player, sum(score) as score from
                    (select first_player as player, first_score as score from Matches
                    union all
                    select second_player, second_score from Matches) s
                group by player) PlayerScores
            where Players.player_id = PlayerScores.player
            group by group_id)
```

첫번째 답이다.

```sql
select group_id as GROUP_ID, min(player_id) as PLAYER_ID
from Players,
    (select player, sum(score) as score from
        (select first_player as player, first_score as score from Matches
        union all
        select second_player, second_score from Matches) s
    group by player) PlayerScores
where Players.player_id = PlayerScores.player and (group_id, score) in
	(select group_id, max(score)
	from Players,
		(select player, sum(score) as score from
			(select first_player as player, first_score as score from Matches
			union all
			select second_player, second_score from Matches) s
		group by player) PlayerScores
	where Players.player_id = PlayerScores.player
	group by group_id)
group by group_id
```

PlayerScores 가 두번 생성된다. 최적화 하자.

```sql
select p.group_id, ps.player_id, sum(ps.score) as score from Players p,
	(select first_player as player_id, first_score as score from Matches
	union all
	select second_player, second_score from Matches) ps
where p.player_id = ps.player_id
group by ps.player_id order by group_id, score desc, player_id
```

group_id 로 그룹화 하자.

```sql
SELECT group_id, player_id FROM (
	select p.group_id, ps.player_id, sum(ps.score) as score from Players p,
	    (select first_player as player_id, first_score as score from Matches
	    union all
	    select second_player, second_score from Matches) ps
	where p.player_id = ps.player_id
	group by ps.player_id order by group_id, score desc, player_id) top_scores
group by group_id
```

# Implementation

```sql
-- 458ms 48.53% 0B 100.00%
select group_id, player_id from (
	select p.group_id, ps.player_id, sum(ps.score) as score from Players p,
	    (select first_player as player_id, first_score as score from Matches
	    union all
	    select second_player, second_score from Matches) ps
	where p.player_id = ps.player_id
	group by ps.player_id order by group_id, score desc, player_id) top_scores
group by group_id
```
