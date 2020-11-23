# Problem

[User Activity for the Past 30 Days II](https://leetcode.com/problems/user-activity-for-the-past-30-days-ii/)

# Idea

## Tables

* Activity

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| session_id    | int     |
| activity_date | date    |
| activity_type | enum    |
+---------------+---------+
There is no primary key for this table, it may have duplicate rows.
The activity_type column is an ENUM of type ('open_session', 'end_session', 'scroll_down', 'send_message').
The table shows the user activities for a social media website.
Note that each session belongs to exactly one user.
```

# Implementation

```SQL
SELECT IFNULL(ROUND(COUNT(DISTINCT session_id)/COUNT(DISTINCT user_id), 2), 0.00)
  AS average_sessions_per_user
FROM Activity
WHERE activity_date >= '2019-06-28' AND activity_date <= '2019-07-27';
```
