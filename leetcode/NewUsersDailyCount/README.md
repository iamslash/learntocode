# Problem

[New Users Daily Count](https://leetcode.com/problems/new-users-daily-count/)

# Schema

```
Traffic

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| activity      | enum    |
| activity_date | date    |
+---------------+---------+
There is no primary key for this table, it may have duplicate rows.
The activity column is an ENUM type of ('login', 'logout', 'jobs', 'groups', 'homepage').
```

# Example

```
Traffic table:
+---------+----------+---------------+
| user_id | activity | activity_date |
+---------+----------+---------------+
| 1       | login    | 2019-05-01    |
| 1       | homepage | 2019-05-01    |
| 1       | logout   | 2019-05-01    |
| 2       | login    | 2019-06-21    |
| 2       | logout   | 2019-06-21    |
| 3       | login    | 2019-01-01    |
| 3       | jobs     | 2019-01-01    |
| 3       | logout   | 2019-01-01    |
| 4       | login    | 2019-06-21    |
| 4       | groups   | 2019-06-21    |
| 4       | logout   | 2019-06-21    |
| 5       | login    | 2019-03-01    |
| 5       | logout   | 2019-03-01    |
| 5       | login    | 2019-06-21    |
| 5       | logout   | 2019-06-21    |
+---------+----------+---------------+

Result table:
+------------+-------------+
| login_date | user_count  |
+------------+-------------+
| 2019-05-01 | 1           |
| 2019-06-21 | 2           |
+------------+-------------+
Note that we only care about dates with non zero user count.
The user with id 5 first logged in on 2019-03-01 so he's not counted on 2019-06-21.
```

# Idea

오늘의 날짜는 '2019-06-30' 이다. 90 일 전부터 오늘까지 최초로 로그인한
유저들의 숫자와 로그인했던 날짜들의 목록을 구하는 문제이다.

# Implementation

```sql
-- 357ms 73.42%
SELECT
  login_date, COUNT(a.user_id) AS user_count
FROM
  (SELECT
    user_id, MIN(activity_date) AS login_date
  FROM 
    Traffic
  WHERE
    activity = 'login'
  GROUP BY user_id) a
WHERE
  login_date BETWEEN DATE_ADD('2019-06-30', INTERVAL -90 day) AND
    '2019-06-30'
GROUP BY login_date
```
