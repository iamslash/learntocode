# Problem

[The Change in Global Rankings](https://leetcode.com/problems/the-change-in-global-rankings/)

# Implementation

* rank 의 차이는 `new_rank - old_rank` 이다.
* rank 는 `ROW_NUMBER OVER` 의 차이를 이용한다.
* `points_change` 는 팀당 하나이다???

```sql
-- 768ms 50.36% 0B 100.00%
SELECT a.team_id, 
       a.name,
       CAST(ROW_NUMBER() OVER(ORDER BY points DESC, name ASC) AS SIGNED) -
       CAST(ROW_NUMBER() OVER(ORDER BY points + points_change DESC, name ASC) AS SIGNED) AS rank_diff
  FROM TeamPoints AS a
  JOIN PointsChange AS b
    ON a.team_id = b.team_id;
```
