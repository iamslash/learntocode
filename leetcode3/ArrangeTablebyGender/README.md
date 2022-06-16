# Problem

[Arrange Table by Gender](https://leetcode.com/problems/arrange-table-by-gender/)

# Implementation

```
+---------+--------+
| user_id | gender |
+---------+--------+
| 4       | male   |
| 7       | female |
| 2       | other  |
| 5       | male   |
| 3       | female |
| 8       | male   |
| 6       | other  |
| 1       | other  |
| 9       | female |
+---------+--------+

SELECT *, RANK() OVER(PARTITION BY gender ORDER BY user_id) AS rnk1;

+---------+--------+------+
| user_id | gender | rnk1 |
+---------+--------+------+
| 3       | female | 1    |
| 7       | female | 2    |
| 9       | female | 3    |
| 4       | male   | 1    |
| 5       | male   | 2    |
| 8       | male   | 3    |
| 1       | other  | 1    |
| 2       | other  | 2    |
| 6       | other  | 3    |
+---------+--------+------+
```

```sql
-- 1226ms 100.00% 0B 100.00%
WITH r AS (
  SELECT *,
         RANK() OVER(PARTITION BY gender ORDER BY user_id) AS rnk1,
         IF(gender='female', 0, IF(gender='other', 1, 2)) AS rnk2
    FROM Genders
) 
  SELECT r.user_id, 
         r.gender
    FROM r
ORDER BY rnk1, rnk2;
```
