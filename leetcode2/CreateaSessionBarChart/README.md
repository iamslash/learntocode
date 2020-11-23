# Problem

[Create a Session Bar Chart](https://leetcode.com/problems/create-a-session-bar-chart/)

# Idea

```
SQL Schema
Table: Sessions

+---------------------+---------+
| Column Name         | Type    |
+---------------------+---------+
| session_id          | int     |
| duration            | int     |
+---------------------+---------+
session_id is the primary key for this table.
duration is the time in seconds that a user has visited the application.
```

```
Sessions table:
+-------------+---------------+
| session_id  | duration      |
+-------------+---------------+
| 1           | 30            |
| 2           | 199           |
| 3           | 299           |
| 4           | 580           |
| 5           | 1000          |
+-------------+---------------+

Result table:
+--------------+--------------+
| bin          | total        |
+--------------+--------------+
| [0-5>        | 3            |
| [5-10>       | 1            |
| [10-15>      | 0            |
| 15 or more   | 1            |
+--------------+--------------+

For session_id 1, 2 and 3 have a duration greater or equal than 0 minutes and less than 5 minutes.
For session_id 4 has a duration greater or equal than 5 minutes and less than 10 minutes.
There are no session with a duration greater or equial than 10 minutes and less than 15 minutes.
For session_id 5 has a duration greater or equal than 15 minutes.
```

# Implementation

```sql
-- 896ms 27.51% 0B 100.00%
(SELECT "[0-5>" AS BIN, SUM(CASE WHEN duration >= 0 AND duration < 300 THEN 1 ELSE 0 END) AS TOTAL
FROM Sessions)
UNION ALL
(SELECT "[5-10>" AS BIN, SUM(CASE WHEN duration >= 300 AND duration < 600 THEN 1 ELSE 0 END) AS TOTAL
FROM Sessions)
UNION ALL
(SELECT "[10-15>" AS BIN, SUM(CASE WHEN duration >= 600 AND duration < 900 THEN 1 ELSE 0 END) AS TOTAL
FROM Sessions)
UNION ALL
(SELECT "15 or more" AS BIN, SUM(CASE WHEN duration >= 900 THEN 1 ELSE 0 END) AS TOTAL
FROM Sessions)
```
