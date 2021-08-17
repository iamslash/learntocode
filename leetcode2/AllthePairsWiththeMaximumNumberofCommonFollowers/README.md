# Problem

[All the Pairs With the Maximum Number of Common Followers](https://leetcode.com/problems/all-the-pairs-with-the-maximum-number-of-common-followers/)

# Implementation

```sql
-- 941ms 7.42% 0B 100.00%
WITH t AS (
  SELECT a.user_id AS user1_id,
         b.user_id AS user2_id,
         COUNT(*) AS total
    FROM Relations AS a
    JOIN Relations AS b
      ON a.user_id < b.user_id AND
         a.follower_id = b.follower_id
GROUP BY a.user_id, b.user_id         
)

SELECT user1_id, 
       user2_id
  FROM t
 WHERE total = (SELECT MAX(total) FROM t);
```
