# Problem

[Strong Friendship](https://leetcode.com/problems/strong-friendship/)

# Implementation

too difficult

```sql
-- 309ms 100.00% 0B 100.00%
WITH pair AS (
   SELECT user1_id, user2_id 
     FROM Friendship
UNION ALL 
   SELECT user2_id AS user1_id,
          user1_id AS user2_id
     FROM Friendship)

   SELECT a.user1_id, a.user2_id,
          COUNT(pair.user2_id) AS common_friend
     FROM Friendship a
LEFT JOIN pair 
       ON a.user2_id = pair.user1_id
    WHERE pair.user2_id IN(SELECT user2_id
                             FROM pair
                            WHERE user1_id = a.user1_id)
 GROUP BY a.user1_id, a.user2_id
   HAVING COUNT(pair.user2_id) >= 3   
```
