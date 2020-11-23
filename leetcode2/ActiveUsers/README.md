# Problem

[Active Users](https://leetcode.com/problems/active-users/)

# Idea

```
Accounts table:
+----+----------+
| id | name     |
+----+----------+
| 1  | Winston  |
| 7  | Jonathan |
+----+----------+

Logins table:
+----+------------+
| id | login_date |
+----+------------+
| 7  | 2020-05-30 |
| 1  | 2020-05-30 |
| 7  | 2020-05-31 |
| 7  | 2020-06-01 |
| 7  | 2020-06-02 |
| 7  | 2020-06-02 |
| 7  | 2020-06-03 |
| 1  | 2020-06-07 |
| 7  | 2020-06-10 |
+----+------------+

Result table:
+----+----------+
| id | name     |
+----+----------+
| 7  | Jonathan |
+----+----------+
User Winston with id = 1 logged in 2 times only in 2 different days, so, Winston is not an active user.
User Jonathan with id = 7 logged in 7 times in 6 different days, five of them were consecutive days, so, Jonathan is an active user.
```

# Implementation

```SQL
SELECT DISTINCT a.id, () name
FROM Logins a, Logins b
WHERE a.id = b.id
  AND DATEDIFF(a.login_date, b.login_date) BETWEEN 1 AND 4
GROUP BY a.id, a.login_date
HAVING COUNT(DISTINCT b.login_date) = 4;
```

```SQL
-- 1630ms 54.02% 0B 100.00%
SELECT DISTINCT a.id, (
  SELECT name FROM Accounts WHERE id = a.id
) name
FROM Logins a, Logins b
WHERE a.id = b.id
  AND DATEDIFF(a.login_date, b.login_date) BETWEEN 1 AND 4
GROUP BY a.id, a.login_date
HAVING COUNT(DISTINCT b.login_date) = 4;
```
