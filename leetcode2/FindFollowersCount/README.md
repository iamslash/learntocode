# Problem

[Find Followers Count](https://leetcode.com/problems/find-followers-count/)

# Implementation

```sql
-- 1048ms 100.00% 0B 100.00%
  SELECT user_id, 
         COUNT(follower_id) as followers_count
    FROM Followers
GROUP BY user_id
ORDER BY user_id;
```
