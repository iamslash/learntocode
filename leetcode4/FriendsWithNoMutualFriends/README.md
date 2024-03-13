# Problem

[Friends With No Mutual Friends](https://leetcode.com/problems/friends-with-no-mutual-friends/)

# Implementation

```
WITH all_pairs AS (
),
shared_pairs AS (
)
SELECT user_id1, user_id2
  FROM Friends
 WHERE (user_id1, user_id2) 
NOT IN (SELECT user_id1, user_id2
         FROM shared_pairs)
ORDER BY user_id1, 
         user_id2;
```

```
-- 1235ms 16.57% 0B 100.00%
WITH all_pairs AS (
   SELECT user_id1 AS user_id,
          user_id2 AS frnd_id
     FROM Friends
UNION ALL 
   SELECT user_id2 AS user_id,
          user_id1 AS frnd_id
     FROM Friends
),
shared_pairs AS (
   SELECT a1.user_id AS user_id1,
          a2.user_id AS user_id2
     FROM all_pairs a1
     JOIN all_pairs a2
       ON a1.frnd_id = a2.frnd_id
)
SELECT user_id1, user_id2
  FROM Friends
 WHERE (user_id1, user_id2) NOT IN 
       (SELECT user_id1, user_id2
          FROM shared_pairs)
ORDER BY user_id1, 
         user_id2;

```
