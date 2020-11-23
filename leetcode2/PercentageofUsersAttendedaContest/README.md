# Problem

[Percentage of Users Attended a Contest](https://leetcode.com/problems/percentage-of-users-attended-a-contest/)

# Implementation

```sql
-- 800ms 100.00% 0B 100.00%
  SELECT contest_id, 
         ROUND(COUNT(user_id) / 
               (SELECT COUNT(*) FROM Users) * 100, 2) AS percentage
    FROM Register
GROUP BY contest_id
ORDER BY percentage DESC,
         contest_id ASC;
```
