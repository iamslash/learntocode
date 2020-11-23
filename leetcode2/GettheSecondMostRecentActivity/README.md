# Problem

[Get the Second Most Recent Activity](https://leetcode.com/problems/get-the-second-most-recent-activity/)

# Idea

```
SQL Schema
Table: UserActivity

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| username      | varchar |
| activity      | varchar |
| startDate     | Date    |
| endDate       | Date    |
+---------------+---------+
This table does not contain primary key.
This table contain information about the activity performed of each user in a period of time.
A person with username performed a activity from startDate to endDate.
```

```
UserActivity table:
+------------+--------------+-------------+-------------+
| username   | activity     | startDate   | endDate     |
+------------+--------------+-------------+-------------+
| Alice      | Travel       | 2020-02-12  | 2020-02-20  |
| Alice      | Dancing      | 2020-02-21  | 2020-02-23  |
| Alice      | Travel       | 2020-02-24  | 2020-02-28  |
| Bob        | Travel       | 2020-02-11  | 2020-02-18  |
+------------+--------------+-------------+-------------+

Result table:
+------------+--------------+-------------+-------------+
| username   | activity     | startDate   | endDate     |
+------------+--------------+-------------+-------------+
| Alice      | Dancing      | 2020-02-21  | 2020-02-23  |
| Bob        | Travel       | 2020-02-11  | 2020-02-18  |
+------------+--------------+-------------+-------------+

The most recent activity of Alice is Travel from 2020-02-24 to 2020-02-28, before that she was dancing from 2020-02-21 to 2020-02-23.
Bob only has one record, we just take that one.
```

# Implementation

```sql
SELECT *
FROM UserActivity
GROUP BY username
HAVING COUNT(*) = 1
```

```sql
SELECT *
FROM UserActivity
GROUP BY username
HAVING COUNT(*) = 1

UNION ALL

SELECT u1.*
FROM ()
GROUP BY u1.username, u1.endDate
HAVING COUNT(u2.endDate) = 1
```

```sql
-- 736ms 24.72% 0B 100.00%
SELECT *
FROM UserActivity
GROUP BY username
HAVING COUNT(*) = 1

UNION ALL

SELECT u1.*
FROM UserActivity u1
LEFT JOIN UserActivity u2
  ON u1.username = u2.username AND u1.endDate < u2.endDate  
GROUP BY u1.username, u1.endDate
HAVING COUNT(u2.endDate) = 1
```
