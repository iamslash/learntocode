# Problem

[The Latest Login in 2020](https://leetcode.com/problems/the-latest-login-in-2020/)

# Implementation

```sql
-- 480ms 85.42% 0B 100.00%
  SELECT user_id, 
         MAX(time_stamp) AS last_stamp
    FROM Logins
   WHERE YEAR(time_stamp)='2020'
GROUP BY user_id
```
