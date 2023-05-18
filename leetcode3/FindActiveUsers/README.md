# Problem

[Find Active Users](https://leetcode.com/problems/find-active-users/)

# Implementation

```sql
-- 4443ms 5.34% 0B 100.00%
SELECT DISTINCT user_id
  FROM (
    SELECT user_id,
           IF(DATEDIFF(created_at, 
             LAG(created_at, 1) OVER(PARTITION BY user_id ORDER BY created_at)) 
             <= 7, 1, 0) AS flag
      FROM users 
  ) tmp
 WHERE flag = 1;
```
